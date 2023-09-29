/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:56:47 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 22:44:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	can_ray_hit_the_plane(t_ray *ray, t_bv *bv, int flag, int axis);

void	traverse_tree(t_tree *tree, t_ray *ray,
		void (*f)(t_object *, void *), void *arg)
{
}

static int	is_bv_in_raypath(t_ray *ray, t_bv *bv)
{
	int			region_info;
	t_vector	temp_point;
	t_real		position;

	region_info = get_flag_region_info(ray->position, bv);
	if (region_info == 0)
		return (1);
	if (region_info & FLAG_BV_REGION_X)
		if (can_ray_hit_the_plane(ray, bv, region_info, M_AXIS_X))
			return (1);
	if (region_info & FLAG_BV_REGION_Y)
		if (can_ray_hit_the_plane(ray, bv, region_info, M_AXIS_Y))
			return (1);
	if (region_info & FLAG_BV_REGION_Z)
		if (can_ray_hit_the_plane(ray, bv, region_info, M_AXIS_Z))
			return (1);
	return (0);
}

static int	can_ray_hit_the_plane(t_ray *ray, t_bv *bv, int flag, int axis)
{
	const int	top_region[3] = {FLAG_BV_REGION_X_TOP,
		FLAG_BV_REGION_Y_TOP, FLAG_BV_REGION_Z_TOP};
	const int	side1[3] = {M_AXIS_Y, M_AXIS_Z, M_AXIS_X};
	const int	side2[3] = {M_AXIS_Z, M_AXIS_X, M_AXIS_Y};
	t_real		position;
	t_vector	temp_point;

	position = bv->min[axis];
	if (flag & top_region[axis])
		position = bv->max[axis];
	if ((position - ray->position[axis]) * ray->normal_unit[axis] < 0)
		return (0);
	vec_copy(temp_point, ray->position);
	move_point_onto_plane(temp_point, ray->normal_unit, position, axis);
	if (is_point_in_plane(temp_point, bv, side1[axis], side2[axis]))
		return (1);
	return (0);
}
