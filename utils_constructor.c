/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:12:17 by sunko             #+#    #+#             */
/*   Updated: 2023/12/07 21:25:14 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	gen_vec3(const double x, const double y, const double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point3	gen_point3(const double x, const double y, const double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color3	gen_color3(const double r, const double g, const double b)
{
	t_color3	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	set_vet(t_vec3 *vec, const double x, const double y, const double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void	set_color(t_color3 *color, const double r, const double g, const double v)
{
	color->r = r;
	color->g = g;
	color->b = v;
}
