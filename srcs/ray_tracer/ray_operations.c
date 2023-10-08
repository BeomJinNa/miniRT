/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:27:13 by bena              #+#    #+#             */
/*   Updated: 2023/10/08 20:13:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

/*
 * Caution! Use only UNIT VECTORS in arguments (vectors of size 1)
 */
void	*get_reflected_ray(t_vector buffer, t_vector ray_normal_unit,
			t_vector surface_normal_unit)
{
	t_vector	reflection_normal2;

	vec_product_scalar(reflection_normal2, surface_normal_unit,
		-2 * vec_dot_product(ray_normal_unit, surface_normal_unit));
	vec_add(buffer, ray_normal_unit, reflection_normal2);
	return (buffer);
}

t_real	get_nearest_point_with_ray(t_ray *ray,
			t_vector position, t_vector normal_unit)
{
	t_vector		displacement;
	t_vector		vertical_unit;
	t_vector		shift_ray_position;
	t_vector		proj_displacement;
	t_real			temp;

	vec_subtract(displacement, position, ray->position);
	vec_cross_product(vertical_unit, ray->normal_unit, normal_unit);
	vec_norm(vertical_unit, vertical_unit);
	vec_product_scalar(shift_ray_position, vertical_unit,
		vec_dot_product(displacement, vertical_unit));
	vec_add(shift_ray_position, shift_ray_position, ray->position);
	vec_subtract(proj_displacement, position, shift_ray_position);
	temp = 1 / sqrtf(1 - vec_dot_product(ray->normal_unit, normal_unit));
	vec_product_scalar(vertical_unit, ray->normal_unit,
		vec_dot_product(proj_displacement, ray->normal_unit));
	vec_subtract(vertical_unit, proj_displacement, vertical_unit);
	temp = vec_size(vertical_unit) * temp;
	if (vec_dot_product(displacement, normal_unit)
		> vec_dot_product(ray->normal_unit, normal_unit))
		return (-temp);
	return (temp);
}
