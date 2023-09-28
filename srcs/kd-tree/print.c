/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:58:38 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 17:09:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "stat.h"
#include <stdio.h>

static void	print_node_connection(int depth, int last_sibling, int *last_level);
static void	print_node(t_tree *node, int depth,
				int last_sibling, int *last_level);
static void	print_object(void *object);

void	print_tree(t_tree *root)
{
	int	last_level[M_TREE_MAX_DEPTH];

	ft_memset(last_level, 0, sizeof(last_level));
	print_node(root, 0, 1, last_level);
}

/*
 * When the node is right-child or left-child with NULL on the right,
 * it is the last sibling. (binary tree characteristic)
 */
static void	print_node(t_tree *node, int depth,
				int last_sibling, int *last_level)
{
	int			number_of_objects;
	const char	axis[3] = {'X', 'Y', 'Z'};

	if (node == NULL)
		return ;
	number_of_objects = ft_lstsize(node->objects);
	print_node_connection(depth, last_sibling, last_level);
	if (number_of_objects == 0)
		printf("Node \033[33m(depth: %d) \033[0m"
			"\033[90m[%c]\033[0m\n",
			depth, axis[node->axis]);
	else
		printf("\033[35mLeaf\033[0m \033[36m(objects: %d)\033[0m\n",
			number_of_objects);
	last_level[depth] = last_sibling;
	print_node(node->left, depth + 1, node->right == NULL, last_level);
	print_node(node->right, depth + 1, 1, last_level);
}

static void	print_node_connection(int depth, int last_sibling, int *last_level)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		if (last_level[i++])
			printf("      ");
		else
			printf("\033[32m|\033[0m     ");
	}
	if (depth > 0)
	{
		if (last_sibling)
			printf("\033[32m+---- \033[0m");
		else
			printf("\033[32m|---- \033[0m");
	}
	else
		printf("\033[31m[ROOT]\033[0m");
}

void	print_object_list(t_list *list)
{
	if (list == NULL)
		return ;
	ft_lstiter(list, print_object);
}

static void	print_object(void *object)
{
	t_object	*obj;

	obj = (t_object *)object;
	if (obj->type == M_OBJECT_TYPE_SPHERE)
		printf("Type : Sphere ");
	else if (obj->type == M_OBJECT_TYPE_CONE)
		printf("Type : Cone ");
	else if (obj->type == M_OBJECT_TYPE_CYLINDER)
		printf("Type : Cylinder ");
	else if (obj->type == M_OBJECT_TYPE_PLANE)
		printf("Type : Plane ");
	else
	{
		printf("Type : Unknown(%d) ", obj->type);
		return ;
	}
	printf("[%.1f ~ %.1f, %1.f ~ %1.f, %1.f ~ %1.f]\n", obj->bv.min[0],
		obj->bv.max[0], obj->bv.min[1], obj->bv.max[1], obj->bv.min[2],
		obj->bv.max[2]);
}
