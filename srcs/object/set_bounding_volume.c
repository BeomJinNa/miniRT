/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounding_volume.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:07:25 by bena              #+#    #+#             */
/*   Updated: 2023/10/30 18:34:14 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <math.h>

static t_bv	get_plane_bv(t_vector position, t_vector normal, t_real radius);
static t_bv	get_point_bv(t_vector point);

void	set_bv_on_plane(t_object *plane)
{
	plane->bv = get_plane_bv(plane->u_data.plane.position,
			plane->u_data.plane.normal, plane->u_data.plane.radius);
}

void	set_bv_on_cylinder(t_object *cylinder)
{
	t_bv	plane1;
	t_bv	plane2;

	plane1 = get_plane_bv(cylinder->u_data.cylinder.position,
			cylinder->u_data.cylinder.normal, 10 * cylinder->u_data.cylinder.radius);//TEST
	vec_add(plane2.min, plane1.min, cylinder->u_data.cylinder.normal);
	vec_add(plane2.max, plane1.max, cylinder->u_data.cylinder.normal);
	cylinder->bv = plane1;
	update_min_max_boundary(&cylinder->bv, &plane2);
}

void	set_bv_on_cone(t_object *cone)
{
	t_bv		plane;
	t_bv		tip;
	t_vector	tip_p;

	plane = get_plane_bv(cone->u_data.cone.position,
			cone->u_data.cone.normal, cone->u_data.cone.radius);
	cone->bv = plane;
	vec_add(tip_p, cone->u_data.cone.position, cone->u_data.cone.normal);
	tip = get_point_bv(tip_p);
	update_min_max_boundary(&cone->bv, &tip);
}

static t_bv	get_plane_bv(t_vector position, t_vector normal, t_real radius)
{
	t_bv		output;
	t_vector	unit;
	t_real		cos_direction;
	t_real		sin_direction;
	int			axis;

	axis = 0;
	while (axis < 3)
	{
		unit[0] = 0;
		unit[1] = 0;
		unit[2] = 0;
		unit[axis] = 1.0;
		cos_direction = vec_cosine_similarity(normal, unit);
		sin_direction = sqrt(1 - cos_direction * cos_direction);
		output.max[axis] = position[axis] + sin_direction * radius;
		output.min[axis] = position[axis] - sin_direction * radius;
		axis++;
	}
	return (output);
}

static t_bv	get_point_bv(t_vector point)
{
	t_bv	output;

	vec_copy(output.min, point);
	vec_copy(output.max, point);
	return (output);
}
