/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_a_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:51:28 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 08:16:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "stat.h"

static void	get_value_from_hitpoint(t_vector buffer,
				t_intersection *hitpoint, t_data *data, int depth);

void	shoot_a_ray(t_vector buffer, t_ray ray, t_data *data, int depth)
{
	t_intersection	hitpoint;

	vec_set_zero(buffer);
	if (depth > M_SCATTER_MAX_DEPTH)
		return ;
	hitpoint = get_closest_intersection(&ray, data);
	if (hitpoint.object == M_OBJECT_TYPE_NONE)
		return ;
	get_value_from_hitpoint(buffer, &hitpoint, data, depth);
	vec_product_scalar(buffer, buffer, ray.weight);
}

static void	get_value_from_hitpoint(t_vector buffer,
				t_intersection *hitpoint, t_data *data, int depth)
{
	t_ray		temp_ray;
	t_vector	temp_output;

	temp_ray = set_ray(hitpoint->position,
			hitpoint->reflection_direction_unit, hitpoint->reflection_ratio);
	shoot_a_ray(temp_output, temp_ray, data, depth + 1);
	vec_add(buffer, buffer, temp_output);
	compute_lighting_from_spotlights(temp_output, hitpoint, data);
	vec_add(buffer, buffer, temp_output);
	compute_scattering_lights(temp_output, hitpoint, data, depth + 1);
	vec_add(buffer, buffer, temp_output);
	vec_add(buffer, buffer, data->ambient);
}
