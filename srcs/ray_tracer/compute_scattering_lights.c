/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_scattering_lights.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:57:19 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 07:46:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static t_ray	get_next_ray_from_halton_sequence(t_intersection *hitpoint,
					t_real weight, t_real theta, t_real phi);
static t_real	get_random_real_base2(void);
static t_real	get_random_real_base3(void);

void	compute_scattering_lights(t_vector buffer,
			t_intersection *hitpoint, t_data *data, int depth)
{
	t_real		weight;
	t_vector	scattered_light;
	t_ray		temp_ray;
	int			sampled_size;
	t_vector	polar_coordinates;

	vec_set_zero(buffer);
	if (M_SCATTER_SAMPLE_SIZE < 1 || depth > M_SCATTER_MAX_DEPTH)
		return ;
	weight = (1 - hitpoint->reflection_ratio) / (t_real)M_SCATTER_SAMPLE_SIZE;
	polar_coordinates[1] = vec_get_polar_angle_theta(hitpoint->normal_unit);
	polar_coordinates[2] = vec_get_polar_angle_phi(hitpoint->normal_unit);
	sampled_size = 0;
	while (sampled_size < M_SCATTER_SAMPLE_SIZE)
	{
		temp_ray = get_next_ray_from_halton_sequence(hitpoint, weight,
				polar_coordinates[1], polar_coordinates[2]);
		if (temp_ray.weight > 0)
		{
			shoot_a_ray(scattered_light, temp_ray, data, depth);
			vec_add(buffer, buffer, scattered_light);
		}
		sampled_size++;
	}
}

static t_ray	get_next_ray_from_halton_sequence(t_intersection *hitpoint,
					t_real weight, t_real theta, t_real phi)
{
	t_vector	new_direction;

	theta += M_PI * get_random_real_base2() - M_PI_2;
	phi += M_PI * get_random_real_base3() - M_PI_2;
	get_new_unit_vector_by_polar(new_direction, theta, phi);
	weight *= vec_dot_product(hitpoint->normal_unit, new_direction);
	return (set_ray(hitpoint->position, new_direction, weight));
}

static t_real	get_random_real_base2(void)
{
	static unsigned int	seed = 0;
	unsigned int		temp;
	t_real				output;
	t_real				radix;

	output = 0;
	radix = 1.0 / 2.0;
	temp = seed;
	while (temp > 0)
	{
		if (temp & 1)
			output += radix;
		temp >>= 1;
		radix /= 2;
	}
	seed++;
	return (output);
}

static t_real	get_random_real_base3(void)
{
	static unsigned int	seed = 0;
	unsigned int		temp;
	t_real				output;
	t_real				radix;

	output = 0;
	radix = 1.0 / 3.0;
	temp = seed;
	while (temp > 0)
	{
		output += (temp % 3) * radix;
		temp /= 3;
		radix /= 3;
	}
	seed++;
	return (output);
}
