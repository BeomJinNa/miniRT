/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:32:46 by bena              #+#    #+#             */
/*   Updated: 2023/11/02 06:28:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

t_intersection			cylinder_intersection_on_plane(t_ray *ray,
							t_object *cylinder);
t_hit_buffer			calculate_hit_point_cylinder(t_ray *ray,
							t_cylinder *cylinder, t_real nearest_position,
							t_real dist_sq);
static int				is_this_exceptional_case(t_ray *ray,
							t_cylinder *cylinder);
static t_real			get_minimum_distance_square(t_ray *ray,
							t_cylinder *cylinder, t_vector vertical);
static t_intersection	return_intersection(t_ray *ray, t_object *cylinder,
							t_hit_buffer *hitpoint);
static void				apply_checker(t_intersection *output, t_real radius);

t_intersection	get_intersection_on_cylinder(t_ray *ray, t_object *cylinder)
{
	t_cylinder *const	cylinder_ptr = &cylinder->u_data.cylinder;
	t_vector			vertical;
	t_real				minimum_distance_sq;
	t_real				nearest_position;
	t_hit_buffer		hitpoint;

	if (is_this_exceptional_case(ray, cylinder_ptr))
		return (return_void_intersection());
	vec_cross_product(vertical, ray->normal_unit, cylinder_ptr->normal_unit);
	if (is_vector_zero(vertical))
		return (cylinder_intersection_on_plane(ray, cylinder));
	minimum_distance_sq = get_minimum_distance_square(ray,
			cylinder_ptr, vertical);
	if (minimum_distance_sq > cylinder_ptr->radius * cylinder_ptr->radius)
		return (return_void_intersection());
	nearest_position = get_nearest_point_with_ray(ray,
			cylinder_ptr->position, cylinder_ptr->normal_unit);
	hitpoint = calculate_hit_point_cylinder(ray,
			cylinder_ptr, nearest_position, minimum_distance_sq);
	if (is_vector_zero(hitpoint.normal_unit) || hitpoint.dist < 0)
		return (return_void_intersection());
	return (return_intersection(ray, cylinder, &hitpoint));
}

static int	is_this_exceptional_case(t_ray *ray, t_cylinder *cylinder)
{
	t_vector	displacement;
	t_real		ray_height;
	t_vector	center_on_ray_height;
	t_vector	radius_to_ray;

	if (is_real_zero(vec_dot_product(cylinder->normal_unit, ray->normal_unit)))
		return (1);
	vec_subtract(displacement, ray->position, cylinder->position);
	ray_height = vec_dot_product(displacement, cylinder->normal_unit);
	if (ray_height < 0 || cylinder->height < ray_height)
		return (0);
	vec_product_scalar(center_on_ray_height, cylinder->normal_unit, ray_height);
	vec_add(center_on_ray_height, center_on_ray_height, cylinder->position);
	vec_subtract(radius_to_ray, ray->position, center_on_ray_height);
	if (vec_dot_product(radius_to_ray, radius_to_ray)
		< cylinder->radius * cylinder->radius)
		return (1);
	return (0);
}

static t_real	get_minimum_distance_square(t_ray *ray,
					t_cylinder *cylinder, t_vector vertical)
{
	const t_real	vertical_square = vec_dot_product(vertical, vertical);
	t_vector		displacement;
	t_real			distance;

	vec_subtract(displacement, cylinder->position, ray->position);
	distance = vec_dot_product(displacement, vertical);
	return (distance * distance / vertical_square);
}

static t_intersection	return_intersection(t_ray *ray, t_object *cylinder,
							t_hit_buffer *hitpoint)
{
	t_intersection	output;

	vec_copy(output.normal_unit, hitpoint->normal_unit);
	vec_copy(output.position, hitpoint->position);
	output.distance = hitpoint->dist;
	output.ray = ray;
	output.object = cylinder;
	get_reflected_ray(output.reflection_direction_unit,
		ray->normal_unit, output.normal_unit);
	vec_copy(output.reflectance, cylinder->texture.reflectance);
	vec_copy(output.transmittance, cylinder->texture.transmittance);
	output.reflection_ratio = cylinder->texture.reflection_ratio;
	if (cylinder->texture.flags & FLAG_TEXTURE_CHECKER)
		apply_checker(&output, cylinder->u_data.cylinder.radius);
	return (output);
}

static void	apply_checker(t_intersection *output, t_real radius)
{
	t_cylinder *const	cylinder = &output->object->u_data.cylinder;
	t_real				temp_theta;
	t_real				temp_phi;
	t_vector			temp_vec;
	t_vector			cylinder_center;

	temp_theta = 0;
	if (cylinder->normal_unit[0] != 0 || cylinder->normal_unit[1] != 0)
		temp_theta = vec_get_polar_angle_theta(cylinder->normal_unit);
	temp_phi = vec_get_polar_angle_phi(cylinder->normal_unit);
	temp_phi += M_PI_2;
	get_new_unit_vector_by_polar(cylinder_center, temp_theta, temp_phi);
	vec_subtract(temp_vec, output->position, cylinder->position);
	temp_phi = vec_dot_product(cylinder->normal_unit, temp_vec);
	vec_product_scalar(temp_vec, cylinder->normal_unit, temp_phi);
	vec_add(temp_vec, temp_vec, cylinder->position);
	vec_subtract(temp_vec, output->position, temp_vec);
	vec_norm(temp_vec, temp_vec);
	if ((
			(int)floorf(temp_phi / (radius * M_PI / 6.0))
			+ (int)floorf((acosf(vec_dot_product(temp_vec, cylinder_center))
					+ (M_PI / 12.0)) / (M_PI / 6.0))
		) % 2 == 0)
		vec_product_scalar(output->reflectance, output->reflectance, 0.25);
}
