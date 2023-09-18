/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 01:02:15 by bena              #+#    #+#             */
/*   Updated: 2023/09/21 05:10:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "tree.h"

static int	get_optimized_divider(t_real buffer, t_tree *node);

int	split_object_lists(t_list *buffer_splited[2], t_tree *node)
{
	t_real	divider;

	if (get_optimized_divider(divider, node))
		return (1);
	//split_list_data(buffer_splited, node->objects, divider);
	clean_object_list(node->objects);
	node->objects = NULL;
	return (0);
}

static int	get_optimized_divider(t_real buffer, t_tree *node)
{
	if (node == NULL || node->objects == NULL)
		return (-1);
	return (0);
}
