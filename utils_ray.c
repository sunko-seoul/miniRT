/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:47:50 by sunko             #+#    #+#             */
/*   Updated: 2023/12/07 21:51:08 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	gen_ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = get_unit_vec(dir);
	return (ray);
}

t_point3	get_ray_at(t_ray *ray, const double t)
{
	t_point3	at;

	at = get_vec_plus(ray->orig, get_vec_mul_t(ray->dir, t));
	return (at);
}
