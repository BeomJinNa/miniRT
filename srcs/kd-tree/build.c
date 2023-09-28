/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:20:42 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 14:51:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tree.h"
#include "stat.h"

int			split_object_lists(t_list *buffer_splited[2], t_tree *node);
static int	split_node(t_tree *node, int depth);
static int	return_malloc_fail(t_tree *child[2], t_list *list[2]);
static void	link_current_node_to_child_nodes(t_tree *parent, t_tree *child[2]);

//the argument root must be a FREE-ABLE list
int	build_tree(t_tree *root)
{
	if (root == NULL || root->objects == NULL)
		return (-1);
	if (split_node(root, 0))
	{
		remove_tree(&root);
		return (-1);
	}
	return (0);
}

static int	split_node(t_tree *node, int depth)
{
	t_tree	*child[2];
	t_list	*child_object_lists[2];

	get_integrated_bounding_volume(&node->bv, node->objects);
	if (depth >= M_TREE_MAX_DEPTH
		|| ft_lstsize(node->objects) <= M_TREE_MIN_LEAF_SIZE)
		return (0);
	if (split_object_lists(child_object_lists, node))
		return (0);
	child[0] = init_tree(child_object_lists[0]);
	child[1] = init_tree(child_object_lists[1]);
	if (child[0] == NULL || child[1] == NULL)
		return (return_malloc_fail(child, child_object_lists));
	link_current_node_to_child_nodes(node, child);
	if (split_node(node->left, depth + 1))
		return (-1);
	if (split_node(node->right, depth + 1))
		return (-1);
	return (0);
}

static int	return_malloc_fail(t_tree *child[2], t_list *list[2])
{
	if (child[0] != NULL)
		remove_node(&child[0]);
	else
		clean_object_list(list[0]);
	if (child[1] != NULL)
		remove_node(&child[1]);
	else
		clean_object_list(list[1]);
	return (-1);
}

static void	link_current_node_to_child_nodes(t_tree *parent, t_tree *child[2])
{
	parent->left = child[0];
	parent->right = child[1];
	child[0]->parent = parent;
	child[1]->parent = parent;
}
