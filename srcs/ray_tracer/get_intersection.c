/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:06:06 by bena              #+#    #+#             */
/*   Updated: 2023/10/28 03:32:40 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "libft.h"
#include <math.h>

t_intersection	get_intersection_on_plane(t_ray *ray, t_object *plane);
t_intersection	get_intersection_on_sphere(t_ray *ray, t_object *sphere);
t_intersection	get_intersection_on_cylinder(t_ray *ray, t_object *cylinder);
t_intersection	get_intersection_on_cone(t_ray *ray, t_object *cone);

t_intersection	get_intersection(t_ray *ray, t_object *object)
{
	t_intersection	output;
	t_vector		offset;

	if (object->type == M_OBJECT_TYPE_PLANE)
		output = get_intersection_on_plane(ray, object);
	else if (object->type == M_OBJECT_TYPE_SPHERE)
		output = get_intersection_on_sphere(ray, object);
	else if (object->type == M_OBJECT_TYPE_CYLINDER)
		output = get_intersection_on_cylinder(ray, object);
	else
		return (return_void_intersection());
	if (output.object == NULL)
		return (return_void_intersection());
	if (vec_dot_product(ray->normal_unit, output.normal_unit) > 0)
		vec_invert(output.normal_unit, output.normal_unit);
	vec_product_scalar(offset, output.normal_unit, M_SURFACE_OFFSET_SIZE);
	vec_add(output.position, output.position, offset);
	return (output);
}

t_intersection	return_void_intersection(void)
{
	t_intersection	output;

	ft_memset(&output, 0, sizeof(output));
	output.distance = INFINITY;
	return (output);
}
