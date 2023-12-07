/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:30:28 by sunko             #+#    #+#             */
/*   Updated: 2023/12/07 22:43:09 by sunko            ###   ########.fr       */
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
		ft_putendl_fd("Error\ninvailed filename", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(extension, ".rt", 4))
		return (file_name);
	ft_putendl_fd("Error\ninvailed filename", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_parm		parm;
	char		*name;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvaild number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	init_mlx(&parm.mlx_data);
	name = check_rt_extension(argv[1]);
	mlx_put_image_to_window(parm.mlx_data.mlx, parm.mlx_data.win, parm.mlx_data.img, 0, 0);
	mlx_hook(parm.mlx_data.win, ON_DESTROY, 0, destroy_window, &parm.mlx_data);
	mlx_hook(parm.mlx_data.win, ON_KEYDOWN, 0, handle_key_press, &parm);
	mlx_loop(parm.mlx_data.mlx);
}

// TransformScreenToWorld
// 스크린 좌표계 [0, width - 1] x [0, height - 1]
// world 좌표계 [-aspect, +aspect] x [-1, +1]
// aspect = width / height
// xScale = 2.0f * aspect  / width - 1
// yScale = 2.0f / height - 1
//



// render
// 1. 배경색으로 초기화
// 2. vec3 pixelPosWorld = TransformScreenToWorld(vec2(i, j)) => 2차원 픽셀 좌표를 3차원 vec 자료형으로 반환
// 		veiwport에서 z 방향으로 쏘니까 오른손 좌표계에서는 (0, 0, -1);
// 3. Ray pixelRay{ pixelPosWorld, rayDir };
// 4. pixels[size_t(i + width * j)] = vec4(traceRay(pixelRay)); traceRay 값이 rgb color 값을 반환함

// traceRay
// hit = sphere->IntersectRayCollision(ray);  -> 이 함수의 충돌 지점과의 거리를 return 함
