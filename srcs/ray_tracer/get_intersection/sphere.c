/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:32:46 by bena              #+#    #+#             */
/*   Updated: 2023/10/28 16:51:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static t_intersection	return_intersection(t_ray *ray,
							t_object *sphere, t_vector normal, t_real dist);
static void				apply_checker(t_intersection *output);

t_intersection	get_intersection_on_sphere(t_ray *ray, t_object *sphere)
{
	t_sphere *const	sphere_ptr = &sphere->u_data.sphere;
	t_vector		displacement;
	t_vector		path;
	t_vector		normal;
	t_real			distance;

	if (is_point_in_range(ray->position, sphere_ptr->position,
			sphere_ptr->radius))
		return (return_void_intersection());
	vec_subtract(displacement, sphere_ptr->position, ray->position);
	distance = vec_dot_product(displacement, ray->normal_unit);
	if (distance < 0)
		return (return_void_intersection());
	vec_product_scalar(path, ray->normal_unit, distance);
	vec_subtract(normal, path, displacement);
	if (vec_dot_product(normal, normal)
		> sphere_ptr->radius * sphere_ptr->radius)
		return (return_void_intersection());
	distance -= sqrtf(sphere_ptr->radius * sphere_ptr->radius
			- vec_dot_product(normal, normal));
	vec_product_scalar(path, ray->normal_unit, distance);
	vec_subtract(normal, path, displacement);
	return (return_intersection(ray, sphere, normal, distance));
}

static t_intersection	return_intersection(t_ray *ray,
							t_object *sphere, t_vector normal, t_real dist)
{
	t_intersection	output;

	vec_norm(output.normal_unit, normal);
	vec_add(output.position, sphere->u_data.sphere.position, normal);
	output.distance = dist;
	output.ray = ray;
	output.object = sphere;
	get_reflected_ray(output.reflection_direction_unit,
		ray->normal_unit, output.normal_unit);
	vec_copy(output.reflectance, sphere->texture.reflectance);
	vec_copy(output.transmittance, sphere->texture.transmittance);
	output.reflection_ratio = sphere->texture.reflection_ratio;
	if (sphere->texture.flags & FLAG_TEXTURE_CHECKER)
		apply_checker(&output);
	if (sphere->texture.flags & FLAG_TEXTURE_BUMP)
		;
	return (output);
}

static void	apply_checker(t_intersection *output)
{
	t_real			temp_theta;
	t_real			temp_phi;

	temp_theta = 0;
	if (output->normal_unit[0] != 0 || output->normal_unit[1] != 0)
		temp_theta = vec_get_polar_angle_theta(output->normal_unit);
	temp_phi = vec_get_polar_angle_phi(output->normal_unit);
	if (((int)floorf(temp_theta / (M_PI / 6))
			+ (int)floorf(temp_phi / (M_PI / 6))) % 2 == 0)
		vec_product_scalar(output->reflectance, output->reflectance, 0.25);
}
