/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:57:23 by sunko             #+#    #+#             */
/*   Updated: 2023/12/08 00:11:14 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	gen_camera(t_screen *screen, t_point3 orig)
{
	t_camera		cam;
	const double	focal_len = 1.0;
	const double	viewport_height = 2.0;

	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * screen->aspect;
	cam.focal_len = focal_len;
	cam.viewport_u = gen_vec3(cam.viewport_w, 0, 0);
	cam.viewport_v = gen_vec3(0, cam.viewport_h, 0);
	cam.left_bottom = get_vec_minus(
		get_vec_minus(
			get_vec_minus(cam.orig, get_vec_divide(cam.viewport_u, 2))
			, get_vec_divide(cam.viewport_v, 2))
			, gen_vec3(0, 0, cam.focal_len));
	return (cam);
}

t_screen	get_screen(void)
{
	const double	width = 1920;
	const double	height = 1080;
	t_screen		screen;

	screen.width = width;
	screen.height = height;
	screen.aspect = width / height;
	return (screen);
}
