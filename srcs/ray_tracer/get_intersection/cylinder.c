/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:32:46 by bena              #+#    #+#             */
/*   Updated: 2023/10/17 08:03:42 by bena             ###   ########.fr       */
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
	if (is_vector_zero(hitpoint.normal_unit))
		return (return_void_intersection());
	return (return_intersection(ray, cylinder, &hitpoint));
}

static int	is_this_exceptional_case(t_ray *ray, t_cylinder *cylinder)
{
	t_vector	displacement;
	t_vector	proj_displacement;
	t_real		proj_disp_size;

	vec_subtract(displacement, cylinder->position, ray->position);
	if (is_real_zero(vec_dot_product(displacement, cylinder->normal_unit)))
		return (1);
	proj_disp_size = vec_dot_product(displacement, cylinder->normal_unit);
	if (proj_disp_size < 0 || proj_disp_size > cylinder->height)
		return (0);
	vec_product_scalar(proj_displacement,
		cylinder->normal_unit, proj_disp_size);
	if (is_point_in_range(displacement, proj_displacement, cylinder->radius))
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
	if ((cylinder->texture.flags & FLAG_TEXTURE_IMAGE) == 0)
	{
		vec_copy(output.reflectance, cylinder->texture.reflectance);
		vec_copy(output.transmittance, cylinder->texture.transmittance);
		output.reflection_ratio = cylinder->texture.reflection_ratio;
	}
	return (output);
}
