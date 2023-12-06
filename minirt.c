/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:30:28 by sunko             #+#    #+#             */
/*   Updated: 2023/12/06 22:58:02 by sunko            ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_parm		parm;

	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invaild number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	init_mlx(&parm.mlx_data);
	mlx_put_image_to_window(parm.mlx_data.mlx, parm.mlx_data.win, parm.mlx_data.img, 0, 0);
	mlx_hook(parm.mlx_data.win, ON_DESTROY, 0, destroy_window, &parm.mlx_data);
	mlx_hook(parm.mlx_data.win, ON_KEYDOWN, 0, handle_key_press, &parm);
	mlx_loop(parm.mlx_data.mlx);
}

