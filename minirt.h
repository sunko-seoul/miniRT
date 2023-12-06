/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:14:11 by sunko             #+#    #+#             */
/*   Updated: 2023/12/06 22:52:23 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_parm
{
	t_mlx_data	mlx_data;
}	t_parm;

void	init_mlx(t_mlx_data *mlx_data);
int		destroy_window(t_mlx_data *mlx_data);
int		handle_key_press(int keycode, t_parm *parm);

