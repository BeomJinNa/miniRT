/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 01:02:15 by bena              #+#    #+#             */
/*   Updated: 2023/09/22 04:03:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "tree.h"
#include "s_split_buffer.h"
#include "object.h"

void		get_division_cost(t_sp_buffer *buffer,
				t_list *target, t_list *list);
static void	init_buffer(t_sp_buffer *buffer, t_tree *node);
static int	get_optimized_divider(t_tree *node, t_sp_buffer *data);
static int	non_splited(t_list *buffer[2]);
static void	split_list_data(t_list *buffer[2], t_tree *node, t_sp_buffer *data);

int	split_object_lists(t_list *buffer_splited[2], t_tree *node)
{
	t_sp_buffer	data;

	if (node == NULL || node->objects == NULL)
		return (non_splited(buffer_splited));
	init_buffer(&data, node);
	get_optimized_divider(node, &data);
	if (data.included == 0 || data.remainder == 0)
		return (non_splited(buffer_splited));
	split_list_data(buffer_splited, node, &data);
	clean_object_list(node->objects);
	node->objects = NULL;
	return (0);
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

static int	get_optimized_divider(t_tree *node, t_sp_buffer *data)
{
	t_list	*ptr;
	t_list	*target_that_has_minimum_cost;
	t_real	minimum_cost;

	ptr = node->objects;
	target_that_has_minimum_cost = ptr;
	minimum_cost = INFINITY;
	while (ptr)
	{
		data->included = 0;
		data->remainder = data->total;
		get_division_cost(data, ptr, node->objects);
		if (minimum_cost > data->cost)
		{
			minimum_cost = data->cost;
			target_that_has_minimum_cost = ptr;
		}
		ptr = ptr->next;
	}
	get_division_cost(data, target_that_has_minimum_cost, node->objects);
	return (0);
}

static int	non_splited(t_list *buffer[2])
{
	if (buffer != NULL)
	{
		buffer[0] = NULL;
		buffer[1] = NULL;
	}
	return (-1);
}

static void	split_list_data(t_list *buffer[2], t_tree *node, t_sp_buffer *data)
{
	t_list		*ptr;
	t_list		*next;
	const int	axis = data->axis;
	const int	divider = data->divider;

	buffer[0] = NULL;
	buffer[1] = NULL;
	ptr = node->objects;
	while (ptr)
	{
		next = ptr->next;
		ptr->next = NULL;
		if (divider > ((t_object *)ptr->content)->bv.min[axis])
			ft_lstadd_back(&buffer[0], ptr);
		else
			ft_lstadd_back(&buffer[1], ptr);
		ptr = next;
	}
	node->objects = NULL;
	node->axis = axis;
}
