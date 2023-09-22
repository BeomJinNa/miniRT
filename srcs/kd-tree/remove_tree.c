/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:01:32 by bena              #+#    #+#             */
/*   Updated: 2023/09/22 03:24:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

void	remove_node(t_tree **node_ptr);
void	clean_object_list(t_list *list);

void	remove_tree(t_tree **root_ptr)
{
	if ((*root_ptr)->left != NULL)
		remove_tree(&(*root_ptr)->left);
	if ((*root_ptr)->right != NULL)
		remove_tree(&(*root_ptr)->right);
	remove_node(root_ptr);
}

void	remove_node(t_tree **node_ptr)
{
	t_tree	*node;

	if (node_ptr == NULL)
		return ;
	node = *node_ptr;
	if (node != NULL)
	{
		clean_object_list(node->objects);
		free(node);
	}
	*node_ptr = NULL;
}

void	clean_object_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}