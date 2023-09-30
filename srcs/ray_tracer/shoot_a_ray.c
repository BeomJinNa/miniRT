/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_a_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:51:28 by bena              #+#    #+#             */
/*   Updated: 2023/09/30 21:25:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "stat.h"
#include "libft.h"
#include <math.h>

static t_intersection	get_closest_intersection(t_ray *ray, t_data *data);
static void				find_closest_object(t_object *object, void *buffer);

void	*shoot_a_ray(t_vector buffer, t_ray ray, t_data *data)
{
	t_intersection	hitpoint;

	hitpoint = get_closest_intersection(&ray, data);
	if (hitpoint.object == M_OBJECT_TYPE_NONE)
		return (vec_set_zero(buffer));
	//buffer = get_value_from_hitpoint(hitpoint);
	vec_product_scalar(buffer, buffer, ray.weight);
	return (buffer);
}

static t_intersection	get_closest_intersection(t_ray *ray, t_data *data)
{
	t_intersection	output;
	t_object		*hit_object;
	t_real			distance;

	ft_memset(&output, 0, sizeof(output));
	output.ray = ray;
	output.distance = INFINITY;
	traverse_tree(data->tree, ray, find_closest_object, &output);
	return (output);
}

static void	find_closest_object(t_object *object, void *arg)
{
	t_intersection *const	hitpoint = (t_intersection *)arg;
	t_intersection			buffer;

	buffer = get_intersection(hitpoint->ray, object);
	if (hitpoint->object == NULL || buffer.distance < hitpoint->distance)
		*hitpoint = buffer;
}
