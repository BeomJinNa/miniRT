/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:52:52 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 05:49:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "libft.h"
#include <math.h>

static void	find_closest_object(t_object *object, void *arg);

t_intersection	get_closest_intersection(t_ray *ray, t_data *data)
{
	t_intersection	output;

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
	if (buffer.object != NULL)
		if (hitpoint->object == NULL || buffer.distance < hitpoint->distance)
			*hitpoint = buffer;
}
