/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:32:46 by bena              #+#    #+#             */
/*   Updated: 2023/10/28 16:53:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static t_intersection	return_intersection(t_ray *ray,
							t_object *plane, t_vector point, t_real dist);
static void				apply_checker(t_intersection *output);

t_intersection	get_intersection_on_plane(t_ray *ray, t_object *plane)
{
	t_plane *const	plane_ptr = &plane->u_data.plane;
	t_vector		temp;
	t_vector		hitpoint;
	t_real			displacement;
	t_real			proj_ray;

	vec_subtract(temp, plane_ptr->position, ray->position);
	displacement = vec_dot_product(temp, plane_ptr->normal_unit);
	if (is_real_zero(displacement))
		return (return_void_intersection());
	proj_ray = vec_dot_product(ray->normal_unit, plane_ptr->normal_unit);
	if (is_real_zero(proj_ray))
		return (return_void_intersection());
	displacement /= proj_ray;
	if (displacement < 0)
		return (return_void_intersection());
	vec_product_scalar(temp, ray->normal_unit, displacement);
	vec_add(hitpoint, ray->position, temp);
	if (is_point_in_range(hitpoint,
			plane_ptr->position, plane_ptr->radius) == 0)
		return (return_void_intersection());
	return (return_intersection(ray, plane, hitpoint, displacement));
}

static t_intersection	return_intersection(t_ray *ray,
							t_object *plane, t_vector point, t_real dist)
{
	t_intersection	output;

	vec_copy(output.normal_unit, plane->u_data.plane.normal_unit);
	vec_copy(output.position, point);
	output.distance = dist;
	output.ray = ray;
	output.object = plane;
	get_reflected_ray(output.reflection_direction_unit,
		ray->normal_unit, plane->u_data.plane.normal_unit);
	vec_copy(output.reflectance, plane->texture.reflectance);
	vec_copy(output.transmittance, plane->texture.transmittance);
	output.reflection_ratio = plane->texture.reflection_ratio;
	if (plane->texture.flags & FLAG_TEXTURE_CHECKER)
		apply_checker(&output);
	if (plane->texture.flags & FLAG_TEXTURE_BUMP)
		;
	return (output);
}

static void	apply_checker(t_intersection *output)
{
	t_real			temp_theta;
	t_real			temp_phi;
	t_vector		temp_horizontal;
	t_vector		temp_vertical;

	temp_theta = 0;
	if (output->normal_unit[0] != 0 || output->normal_unit[1] != 0)
		temp_theta = vec_get_polar_angle_theta(output->normal_unit);
	temp_phi = vec_get_polar_angle_phi(output->normal_unit);
	temp_phi += M_PI_2;
	get_new_unit_vector_by_polar(temp_horizontal, temp_theta, temp_phi);
	vec_cross_product(temp_vertical, output->normal_unit, temp_horizontal);
	if (
		((int)floorf(
				(vec_dot_product(output->position, temp_horizontal) / 4))
			+ (int)floorf(
				(vec_dot_product(output->position, temp_vertical) / 4)))
		% 2 == 0)
		vec_product_scalar(output->reflectance, output->reflectance, 0.25);
}
