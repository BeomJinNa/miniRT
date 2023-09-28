/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_volume.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:23:51 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 19:20:14 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stddef.h>
#include <math.h>

void	init_bounding_volume(t_bv *bv);
void	update_min_max_boundary(t_bv *buffer, t_bv *target);

void	get_integrated_bounding_volume(t_bv *buffer, t_list *object_list)
{
	t_list	*ptr;
	t_bv	*ptr_bv;

	init_bounding_volume(buffer);
	if (object_list == NULL)
		return ;
	ptr = object_list;
	while (ptr)
	{
		ptr_bv = &((t_object *)ptr->content)->bv;
		update_min_max_boundary(buffer, ptr_bv);
		ptr = ptr->next;
	}
}

void	update_min_max_boundary(t_bv *buffer, t_bv *target)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		if (buffer->min[i] > target->min[i])
			buffer->min[i] = target->min[i];
		if (buffer->max[i] < target->max[i])
			buffer->max[i] = target->max[i];
		i++;
	}
}

void	init_bounding_volume(t_bv *bv)
{
	bv->min[0] = INFINITY;
	bv->min[1] = INFINITY;
	bv->min[2] = INFINITY;
	bv->max[0] = -INFINITY;
	bv->max[1] = -INFINITY;
	bv->max[2] = -INFINITY;
}
