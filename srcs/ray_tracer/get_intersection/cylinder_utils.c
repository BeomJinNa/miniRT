/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:51:40 by bena              #+#    #+#             */
/*   Updated: 2023/10/20 21:33:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "libft.h"
#include <math.h>

static t_hit_buffer	return_nothing(void);

t_hit_buffer	get_buffer_cylinder_side(t_ray *ray,
						t_cylinder *cylinder, t_real ray_center, t_raygap gap)
{
	t_hit_buffer	output;
	t_vector		nearest_position;
	t_vector		displacement;
	t_vector		hitpoint_projection;
	t_real			chord_on_path_inside;

	vec_product_scalar(nearest_position, cylinder->normal_unit, ray_center);
	vec_add(nearest_position, nearest_position, cylinder->position);
	vec_subtract(displacement, nearest_position, ray->position);
	chord_on_path_inside
		= sqrtf(cylinder->radius * cylinder->radius - gap.distance_sq);
	output.dist = vec_dot_product(displacement, ray->normal_unit)
		- (chord_on_path_inside / gap.sine);
	vec_product_scalar(output.position, ray->normal_unit, output.dist);
	vec_subtract(output.normal_unit, output.position, cylinder->position);
	vec_product_scalar(hitpoint_projection, cylinder->normal_unit,
		vec_dot_product(output.normal_unit, cylinder->normal_unit));
	vec_subtract(output.normal_unit, output.normal_unit, hitpoint_projection);
	vec_norm(output.normal_unit, output.normal_unit);
	return (output);
}

t_hit_buffer	get_buffer_cylinder_plane(t_ray *ray,
						t_cylinder *cylinder, t_real cosine)
{
	t_hit_buffer	output;
	t_vector		displacement;

	if (cosine > 0)
		vec_subtract(displacement, cylinder->position, ray->position);
	else
	{
		vec_add(displacement, cylinder->position, cylinder->normal);
		vec_subtract(displacement, displacement, ray->position);
	}
	output.dist = vec_dot_product(ray->normal_unit, displacement);
	vec_product_scalar(displacement, ray->normal_unit, output.dist);
	vec_add(output.position, ray->position, displacement);
	vec_copy(output.normal_unit, cylinder->normal_unit);
	if (cosine < 0)
		vec_product_scalar(output.normal_unit, output.normal_unit, -1.0);
	return (output);
}

t_hit_buffer	calculate_hit_point_cylinder(t_ray *ray,
						t_cylinder *cylinder, t_real ray_center,
						t_real dist_sq)
{
	t_raygap		gap;
	t_real			disp_to_plane;
	t_real			dist_to_normal;
	t_hit_buffer	output;

	gap.cosine = vec_dot_product(ray->normal_unit, cylinder->normal_unit);
	gap.sine = sqrtf(1 - gap.cosine * gap.cosine);
	gap.distance_sq = dist_sq;
	if (is_real_zero(gap.cosine))
		return (get_buffer_cylinder_side(ray, cylinder, ray_center, gap));
	if (gap.cosine > 0)
		disp_to_plane = ray_center;
	else
		disp_to_plane = ray_center - cylinder->height;
	dist_to_normal = disp_to_plane * gap.sine / gap.cosine;
	if (dist_to_normal < -cylinder->radius
		|| dist_to_normal > cylinder->radius + cylinder->height * gap.sine / gap.cosine)
		return (return_nothing());
	if (dist_to_normal < cylinder->radius)
		return (get_buffer_cylinder_plane(ray, cylinder, gap.cosine));
	return (get_buffer_cylinder_side(ray, cylinder, ray_center, gap));
}

static t_hit_buffer	return_nothing(void)
{
	t_hit_buffer	output;

	ft_memset(&output, 0, sizeof(output));
	return (output);
}

t_intersection	cylinder_intersection_on_plane(t_ray *ray, t_object *cylinder)
{
	t_cylinder *const	cylinder_ptr = &cylinder->u_data.cylinder;
	t_intersection		output;
	t_hit_buffer		hitpoint;
	t_real				cosine;

	cosine = vec_dot_product(ray->normal_unit, cylinder_ptr->normal_unit);
	hitpoint = get_buffer_cylinder_plane(ray, cylinder_ptr, cosine);
	vec_copy(output.normal_unit, hitpoint.normal_unit);
	vec_copy(output.position, hitpoint.position);
	output.distance = hitpoint.dist;
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