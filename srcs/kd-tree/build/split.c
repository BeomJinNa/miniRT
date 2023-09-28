/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 01:02:15 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 19:52:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"
#include "s_split_buffer.h"
#include "object.h"
#include <math.h>

void		get_division_cost(t_sp_buffer *buffer,
				t_real divider, t_list *list);
static int	terminate_without_split(t_list *buffer[2]);
static void	init_buffer(t_sp_buffer *buffer, t_tree *node);
static void	get_optimized_divider(t_tree *node, t_sp_buffer *data);
static void	split_list_data(t_list *buffer[2], t_tree *node, t_sp_buffer *data);

int	split_object_lists(t_list *buffer_splited[2], t_tree *node)
{
	t_sp_buffer	data;

	if (node == NULL || node->objects == NULL)
		return (terminate_without_split(buffer_splited));
	init_buffer(&data, node);
	get_optimized_divider(node, &data);
	if (data.included == 0 || data.remainder == 0)
		return (terminate_without_split(buffer_splited));
	split_list_data(buffer_splited, node, &data);
	clean_object_list(node->objects);
	node->objects = NULL;
	return (0);
}

static int	terminate_without_split(t_list *buffer[2])
{
	if (buffer != NULL)
	{
		buffer[0] = NULL;
		buffer[1] = NULL;
	}
	return (-1);
}

static void	init_buffer(t_sp_buffer *buffer, t_tree *node)
{
	buffer->total = ft_lstsize(node->objects);
	buffer->included = -1;
	buffer->remainder = -1;
	if (node->parent == NULL)
		buffer->axis = M_AXIS_X;
	else
		buffer->axis = (node->parent->axis + 1) % 3;
}

static void	get_optimized_divider(t_tree *node, t_sp_buffer *data)
{
	t_list	*ptr;
	t_real	divider_that_has_minimum_cost;
	t_real	minimum_cost;

	ptr = node->objects;
	divider_that_has_minimum_cost
		= ((t_object *)ptr->content)->bv.max[data->axis];
	minimum_cost = INFINITY;
	while (ptr)
	{
		get_division_cost(data,
			((t_object *)ptr->content)->bv.max[data->axis], node->objects);
		if (minimum_cost > data->cost)
		{
			minimum_cost = data->cost;
			divider_that_has_minimum_cost
				= ((t_object *)ptr->content)->bv.max[data->axis];
		}
		ptr = ptr->next;
	}
	data->included = 0;
	data->remainder = data->total;
	get_division_cost(data, divider_that_has_minimum_cost, node->objects);
}

static void	split_list_data(t_list *buffer[2], t_tree *node, t_sp_buffer *data)
{
	t_list		*ptr;
	t_list		*next;
	const int	axis = data->axis;

	buffer[0] = NULL;
	buffer[1] = NULL;
	ptr = node->objects;
	while (ptr)
	{
		next = ptr->next;
		ptr->next = NULL;
		if (((t_object *)ptr->content)->marker == M_OBJECT_MARK_FRONT_GROUP)
			ft_lstadd_back(&buffer[0], ptr);
		else
			ft_lstadd_back(&buffer[1], ptr);
		((t_object *)ptr->content)->marker = M_OBJECT_MARK_INIT;
		ptr = next;
	}
	node->objects = NULL;
	node->axis = axis;
	node->divider = data->divider;
}
