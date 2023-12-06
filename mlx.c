/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:05 by sunko             #+#    #+#             */
/*   Updated: 2023/12/06 22:51:42 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>

void	init_mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	mlx_data->win = mlx_new_window(mlx_data->mlx, 1920, 1080, "miniRT");
	if (!mlx_data->win)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	mlx_data->img = mlx_new_image(mlx_data->mlx, 1920, 1080);
	if (!mlx_data->img)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	mlx_data->addr = mlx_get_data_addr(mlx_data->img,\
		&mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	if (!mlx_data->addr)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}

int	destroy_window(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_key_press(int keycode, t_parm *parm)
{
	if (keycode == 53)
		destroy_window(&parm->mlx_data);
	return (0);
}
