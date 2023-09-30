/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bounding_volume.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:25:54 by bena              #+#    #+#             */
/*   Updated: 2023/09/30 13:57:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	is_point_in_bv(t_vector point, t_bv *bv)
{
	if (point[M_AXIS_X] < bv->min[M_AXIS_X])
		return (0);
	else if (point[M_AXIS_Y] < bv->min[M_AXIS_Y])
		return (0);
	else if (point[M_AXIS_Z] < bv->min[M_AXIS_Z])
		return (0);
	else if (point[M_AXIS_X] > bv->max[M_AXIS_X])
		return (0);
	else if (point[M_AXIS_Y] > bv->max[M_AXIS_Y])
		return (0);
	else if (point[M_AXIS_Z] > bv->max[M_AXIS_Z])
		return (0);
	return (1);
}

int	is_point_in_plane(t_vector point, t_bv *bv, int axis1, int axis2)
{
	if (point[axis1] < bv->min[axis1])
		return (0);
	else if (point[axis1] > bv->max[axis1])
		return (0);
	else if (point[axis2] < bv->min[axis2])
		return (0);
	else if (point[axis2] > bv->max[axis2])
		return (0);
	return (1);
}

/*
 * Determine the region of the bounding volume (bv) in which the point resides.
 * Return a flag indicating the region.
 */
int	get_flag_region_info(t_vector point, t_bv *bv)
{
	int	output;

	output = 0;
	if (point[M_AXIS_X] < bv->min[M_AXIS_X])
		output |= FLAG_BV_REGION_X | FLAG_BV_REGION_X_BOTTOM;
	if (point[M_AXIS_X] > bv->max[M_AXIS_X])
		output |= FLAG_BV_REGION_X | FLAG_BV_REGION_X_TOP;
	if (point[M_AXIS_Y] < bv->min[M_AXIS_Y])
		output |= FLAG_BV_REGION_Y | FLAG_BV_REGION_Y_BOTTOM;
	if (point[M_AXIS_Y] > bv->max[M_AXIS_Y])
		output |= FLAG_BV_REGION_Y | FLAG_BV_REGION_Y_TOP;
	if (point[M_AXIS_Z] < bv->min[M_AXIS_Z])
		output |= FLAG_BV_REGION_Z | FLAG_BV_REGION_Z_BOTTOM;
	if (point[M_AXIS_Z] > bv->max[M_AXIS_Z])
		output |= FLAG_BV_REGION_Z | FLAG_BV_REGION_Z_TOP;
	return (output);
}

/*
 * Move the given point to the plane specified by the normal unit and position.
 * Return the modified point.
 */
void	*move_point_onto_plane(t_vector point, t_vector normal_unit,
			t_real position, int axis)
{
	static const t_vector	unit_x = {1.0, 0, 0};
	static const t_vector	unit_y = {0, 1.0, 0};
	static const t_vector	unit_z = {0, 0, 1.0};
	t_real					unit_distance_to_the_plane;
	t_vector				path_onto_the_plane;

	if (are_values_same(point[axis], position))
		return (point);
	if (axis == M_AXIS_X)
		unit_distance_to_the_plane = vec_dot_product(normal_unit, unit_x);
	else if (axis == M_AXIS_Y)
		unit_distance_to_the_plane = vec_dot_product(normal_unit, unit_y);
	else if (axis == M_AXIS_Z)
		unit_distance_to_the_plane = vec_dot_product(normal_unit, unit_z);
	vec_product_scalar(path_onto_the_plane, normal_unit,
		(position - point[axis]) / unit_distance_to_the_plane);
	vec_add(point, point, path_onto_the_plane);
	return (point);
}
