/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting_from_spotlights.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:28:04 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 05:58:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <stddef.h>

static void	add_value_from_spotlight(t_vector buffer,
				t_intersection *hitpoint, t_light *light);

void	compute_lighting_from_spotlights(t_vector buffer,
			t_intersection *hitpoint, t_data *data)
{
	t_intersection	temp;
	t_list			*ptr;
	t_ray			ray;
	t_light			*light;

	vec_set_zero(buffer);
	ptr = data->lights;
	while (ptr != NULL)
	{
		light = (t_light *)ptr->content;
		vec_subtract(ray.normal_unit, light->position, hitpoint->position);
		if (vec_dot_product(ray.normal_unit, hitpoint->normal_unit) > 0)
		{
			vec_copy(ray.position, hitpoint->position);
			vec_norm(ray.normal_unit, ray.normal_unit);
			temp = get_closest_intersection(&ray, data);
			if (temp.object == NULL)
				add_value_from_spotlight(buffer, hitpoint, light);
		}
		ptr = ptr->next;
	}
}

static void	add_value_from_spotlight(t_vector buffer,
				t_intersection *hitpoint, t_light *light)
{
	t_vector	displacement;
	t_real		distance;
	t_real		cosine;
	t_vector	output;

	vec_subtract(displacement, light->position, hitpoint->position);
	distance = vec_size(displacement);
	cosine = vec_dot_product(hitpoint->normal_unit, displacement) / distance;
	vec_product_scalar(output, light->color,
		M_SCALING_SPOT_LIGHT * cosine / (distance * distance));
	vec_product_element_wise(output, output, hitpoint->reflectance);
	vec_add(buffer, buffer, output);
}
