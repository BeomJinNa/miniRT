/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:28:04 by bena              #+#    #+#             */
/*   Updated: 2023/10/20 20:58:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <stddef.h>

static void	add_value_from_spotlight(t_vector buffer,
				t_intersection *hitpoint, t_light *light);

void	*get_spot_lights(t_vector buffer,
			t_intersection *hitpoint, t_data *data)
{
	t_intersection	temp;
	t_list			*ptr;
	t_ray			ray;

	vec_set_zero(buffer);
	ptr = data->lights;
	while (ptr != NULL)
	{
		vec_subtract(ray.normal_unit, ((t_light *)ptr->content)->position,
			hitpoint->position);
		vec_copy(ray.position, hitpoint->position);
		vec_norm(ray.normal_unit, ray.normal_unit);
		temp = get_closest_intersection(&ray, data);
		if (temp.object == M_OBJECT_TYPE_NONE)
			add_value_from_spotlight(buffer, hitpoint, (t_light *)ptr->content);
		ptr = ptr->next;
	}
	return (buffer);
}

static void	add_value_from_spotlight(t_vector buffer,
				t_intersection *hitpoint, t_light *light)
{
	t_real	attenuation;

	
}
