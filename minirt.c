/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:30:28 by sunko             #+#    #+#             */
/*   Updated: 2023/12/06 23:19:44 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

char	*check_rt_extension(char *file_name)
{
	char	*extension;

	extension = ft_strchr(file_name, '.');
	if (!extension)
	{
		ft_putendl_fd("invailed filename", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(extension, ".rt", 4))
		return (file_name);
	ft_putendl_fd("invailed filename", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_parm		parm;
	char		*name;

	if (argc != 2)
	{
		ft_putendl_fd("Invaild number of arguments Error", 2);
		exit(EXIT_FAILURE);
	}
	init_mlx(&parm.mlx_data);
	name = check_rt_extension(argv[1]);
	mlx_put_image_to_window(parm.mlx_data.mlx, parm.mlx_data.win, parm.mlx_data.img, 0, 0);
	mlx_hook(parm.mlx_data.win, ON_DESTROY, 0, destroy_window, &parm.mlx_data);
	mlx_hook(parm.mlx_data.win, ON_KEYDOWN, 0, handle_key_press, &parm);
	mlx_loop(parm.mlx_data.mlx);
}

