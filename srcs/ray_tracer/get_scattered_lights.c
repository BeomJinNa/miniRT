/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scattered_lights.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:57:19 by bena              #+#    #+#             */
/*   Updated: 2023/10/20 19:19:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_ray	get_next_ray_from_halton_sequence(t_intersection *hitpoint,
					t_real weight);

void	*get_scattered_lights(t_vector buffer,
			t_intersection *hitpoint, t_data *data, int depth)
{
	t_real		weight;
	t_vector	scattered_light;
	t_ray		temp_ray;
	int			sampled_size;

	vec_set_zero(buffer);
	if (M_SCATTER_SAMPLE_SIZE < 1 || depth > M_SCATTER_MAX_DEPTH)
		return (buffer);
	weight = (1 - hitpoint->reflection_ratio) / (t_real)M_SCATTER_SAMPLE_SIZE;
	sampled_size = 0;
	while (sampled_size < M_SCATTER_SAMPLE_SIZE)
	{
		temp_ray = get_next_ray_from_halton_sequence(hitpoint, weight);
		shoot_a_ray(scattered_light, temp_ray, data, depth);
		vec_add(buffer, buffer, scattered_light);
		sampled_size++;
	}
	return (buffer);
}

static t_ray	get_next_ray_from_halton_sequence(t_intersection *hitpoint,
					t_real weight)
{
	static
	return (set_ray(hitpoint->position, hitpoint->normal_unit, weight));
}
