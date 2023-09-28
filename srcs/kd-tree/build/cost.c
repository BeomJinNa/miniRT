/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:23:51 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 19:51:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_split_buffer.h"
#include "object.h"
#include <stddef.h>

static void		init_groups(t_list *list, t_bv *front, t_bv *back);
static void		update_target_ptr(t_list **ptr, t_sp_buffer *buffer, t_bv *bv);
static void		calc_cost(t_sp_buffer *buffer, t_bv front, t_bv back);
static t_real	get_surface_area(t_bv *bv);

void	get_division_cost(t_sp_buffer *buffer, t_real divider, t_list *list)
{
	t_bv	group_front;
	t_bv	group_back;
	t_list	*ptr;
	t_bv	*ptr_bv;

	buffer->divider = divider;
	buffer->cost = 0;
	if (list == NULL)
		return ;
	init_groups(list, &group_front, &group_back);
	ptr = list;
	while (ptr)
	{
		ptr_bv = &((t_object *)ptr->content)->bv;
		((t_object *)ptr->content)->marker = M_OBJECT_MARK_FRONT_GROUP;
		if (ptr_bv->min[buffer->axis] < divider)
			update_min_max_boundary(&group_front, ptr_bv);
		else
		{
			update_min_max_boundary(&group_back, ptr_bv);
			((t_object *)ptr->content)->marker = M_OBJECT_MARK_BACK_GROUP;
		}
		update_target_ptr(&ptr, buffer, ptr_bv);
	}
	calc_cost(buffer, group_front, group_back);
}

static void	init_groups(t_list *list, t_bv *front, t_bv *back)
{
	init_bounding_volume(front);
	init_bounding_volume(back);
}

static void	update_target_ptr(t_list **ptr, t_sp_buffer *buffer, t_bv *bv)
{
	*ptr = (*ptr)->next;
	if (buffer->included < 0 || buffer->remainder < 0)
		return ;
	if (bv->min[buffer->axis] < buffer->divider)
	{
		buffer->included++;
		buffer->remainder--;
	}
}

static void	calc_cost(t_sp_buffer *buffer, t_bv front, t_bv back)
{
	const t_real	surface_front = get_surface_area(&front);
	const t_real	surface_back = get_surface_area(&back);

	buffer->cost
		= surface_front * buffer->included
		+ surface_back * buffer->remainder;
}

static t_real	get_surface_area(t_bv *bv)
{
	const t_real	x = bv->max[0] - bv->min[0];
	const t_real	y = bv->max[1] - bv->min[1];
	const t_real	z = bv->max[2] - bv->min[2];

	if (x < 0 || y < 0 || z < 0)
		return (0);
	return (x * y + y * z + z * x);
}
