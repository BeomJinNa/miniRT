/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:32:46 by bena              #+#    #+#             */
/*   Updated: 2023/10/08 20:31:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static int				is_this_exceptional_case(t_ray *ray,
							t_cylinder *cylinder);
static t_real			get_minimum_distance_square(t_ray *ray,
							t_cylinder *cylinder, t_vector vertical);
static t_intersection	return_intersection(t_ray *ray,
							t_object *cylinder, t_vector normal, t_real dist);

t_intersection	get_intersection_on_cylinder(t_ray *ray, t_object *cylinder)
{
	t_cylinder *const	cylinder_ptr = &cylinder->u_data.cylinder;
	t_vector			vertical;
	t_real				minimum_distance_sq;
	t_real				nearest_position;
	t_intersection		output;

	if (is_this_exceptional_case(ray, cylinder_ptr))
		return (return_void_intersection());
	vec_cross_product(vertical, ray->normal_unit, cylinder_ptr->normal_unit);
//	if (is_vector_zero(vertical))
//		return ();
	minimum_distance_sq = get_minimum_distance_square(ray, cylinder_ptr, vertical);
	if (minimum_distance_sq > cylinder_ptr->radius * cylinder_ptr->radius)
		return (return_void_intersection());
	nearest_position = get_nearest_point_with_ray(ray,
						cylinder_ptr->position, cylinder_ptr->normal_unit);
//	output = calculate_hit_point_cylinder(ray, cylinder, nearest_position);
//	return (return_intersection(output));
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
	vec_product_scalar(proj_displacement, cylinder->normal_unit, proj_disp_size);
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

static t_intersection	return_intersection(t_ray *ray,
							t_object *cylinder, t_vector normal, t_real dist)
{
	t_intersection	output;

	vec_product_scalar(output.normal_unit, normal, 1 / vec_size(normal));
	vec_add(output.position, cylinder->u_data.cylinder.position, normal);
	output.distance = dist;
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
	if (cylinder->texture.flags & FLAG_TEXTURE_BUMP) //Need to Add BUMP module
		;
	return (output);
}
