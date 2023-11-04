/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_scattering_lights.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:57:19 by bena              #+#    #+#             */
/*   Updated: 2023/11/04 23:58:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static void		get_surface_rotation_matrix(t_matrix buffer,
					t_vector normal_unit);
static t_ray	get_next_ray_from_halton_sequence(t_intersection *hitpoint,
					t_real weight, t_matrix rotation);
static t_real	get_random_real_base2(void);
static t_real	get_random_real_base3(void);

void	compute_scattering_lights(t_vector buffer,
			t_intersection *hitpoint, t_data *data, int depth)
{
	t_real		weight;
	t_vector	scattered_light;
	t_ray		temp_ray;
	int			sampled_size;
	t_matrix	rotation;

	vec_set_zero(buffer);
	if (M_SCATTER_SAMPLE_SIZE < 1 || depth > M_SCATTER_MAX_DEPTH)
		return ;
	weight = (1 - hitpoint->reflection_ratio) / (t_real)M_SCATTER_SAMPLE_SIZE;
	get_surface_rotation_matrix(rotation, hitpoint->normal_unit);
	sampled_size = 0;
	while (sampled_size < M_SCATTER_SAMPLE_SIZE)
	{
		temp_ray = get_next_ray_from_halton_sequence(hitpoint, weight,
				rotation);
		if (temp_ray.weight > 0)
		{
			shoot_a_ray(scattered_light, temp_ray, data, depth);
			vec_add(buffer, buffer, scattered_light);
		}
		sampled_size++;
	}
}

static void	get_surface_rotation_matrix(t_matrix buffer, t_vector normal_unit)
{
	t_real		theta;
	t_real		phi;
	t_matrix	rotation_phi;
	t_matrix	rotation_theta;

	theta = vec_get_polar_angle_theta(normal_unit);
	phi = vec_get_polar_angle_phi(normal_unit);
	phi -= M_PI_2;
	set_rotation_matrix_phi(rotation_phi, sinf(phi), cosf(phi));
	set_rotation_matrix_theta(rotation_theta, sinf(theta), cosf(theta));
	mat_product(buffer, rotation_theta, rotation_phi);
}

static t_ray	get_next_ray_from_halton_sequence(t_intersection *hitpoint,
					t_real weight, t_matrix rotation)
{
	t_vector	new_direction;
	t_real		dtheta;
	t_real		dphi;

	dtheta = M_PI * get_random_real_base2() - M_PI_2;
	dphi = M_PI * get_random_real_base3();
	get_new_unit_vector_by_polar(new_direction, dtheta, dphi);
	mat_product_vector(new_direction, rotation, new_direction);
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
