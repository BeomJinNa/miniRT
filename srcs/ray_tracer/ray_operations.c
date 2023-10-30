/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:27:13 by bena              #+#    #+#             */
/*   Updated: 2023/10/30 21:08:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

int			is_vec_watching_the_line(t_vector vec_position,
				t_vector vec_normal_unit, t_vector line_position,
				t_vector line_normal_unit);
static int	is_cross_point_out_of_cylinder(t_ray *ray, t_vector disp,
				t_vector position, t_vector normal_unit);

/*
 * Caution! Use only UNIT VECTORS in arguments (vectors of size 1)
 */
void	get_reflected_ray(t_vector buffer, t_vector ray_normal_unit,
			t_vector surface_normal_unit)
{
	t_vector	reflection_normal2;

	vec_product_scalar(reflection_normal2, surface_normal_unit,
		-2 * vec_dot_product(ray_normal_unit, surface_normal_unit));
	vec_add(buffer, ray_normal_unit, reflection_normal2);
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
	temp = vec_dot_product(ray->normal_unit, normal_unit);
	temp = 1.0f / sqrtf(1.0f - (temp * temp));
	vec_product_scalar(vertical_unit, ray->normal_unit,
		vec_dot_product(proj_displacement, ray->normal_unit));
	vec_subtract(vertical_unit, proj_displacement, vertical_unit);
	temp = vec_size(vertical_unit) * temp;
	vec_norm(displacement, displacement);
	if (is_cross_point_out_of_cylinder(ray, displacement,
			position, normal_unit))
		return (-temp);
	return (temp);
}

static int	is_cross_point_out_of_cylinder(t_ray *ray, t_vector disp,
				t_vector position, t_vector normal_unit)
{
	t_vector	converted_ray_normal;

	vec_copy(converted_ray_normal, ray->normal_unit);
	if (is_vec_watching_the_line(ray->position, ray->normal_unit,
			position, normal_unit) == 0)
		vec_invert(converted_ray_normal, converted_ray_normal);
	if (vec_dot_product(disp, normal_unit)
		> vec_dot_product(converted_ray_normal, normal_unit))
		return (1);
	return (0);
}

int	is_vec_watching_the_line(t_vector vec_position,	t_vector vec_normal_unit,
		t_vector line_position, t_vector line_normal_unit)
{
	t_vector	displacement;
	t_vector	vec_to_the_line;

	vec_subtract(displacement, vec_position, line_position);
	vec_product_scalar(displacement, line_normal_unit,
		vec_dot_product(displacement, line_normal_unit));
	vec_add(displacement, displacement, line_position);
	vec_subtract(vec_to_the_line, displacement, vec_position);
	if (vec_dot_product(vec_to_the_line, vec_normal_unit) > 0)
		return (1);
	return (0);
}

t_real	get_distance_sq_between_line_and_point(t_vector point,
			t_vector line_position, t_vector normal_unit)
{
	t_vector	displacement;
	t_vector	nearest_point;

	vec_subtract(displacement, point, line_position);
	vec_product_scalar(displacement, normal_unit,
		vec_dot_product(displacement, normal_unit));
	vec_add(nearest_point, line_position, displacement);
	vec_subtract(displacement, point, nearest_point);
	return (vec_dot_product(displacement, displacement));
}
