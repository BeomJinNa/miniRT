/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:55:13 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 17:50:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "object.h"

typedef struct s_tree	t_tree;

enum	e_axis_type
{
	M_AXIS_X = 0,
	M_AXIS_Y = 1,
	M_AXIS_Z = 2,
};

struct s_tree
{
	t_tree	*parent;
	t_tree	*left;
	t_tree	*right;
	t_list	*objects;
	int		axis;
	t_real	divider;
	t_bv	bv;
};

/*
 * Caution!!! (init_tree)
 *
 * This function destroys obj_list entered as an argument. Use a copied list.
 * It will not destroy the objects in the list, but the list will be destroyed.
 */
t_tree	*init_tree(t_list *obj_list);
int		build_tree(t_tree *root);
void	print_tree(t_tree *root);
void	remove_tree(t_tree **root_ptr);
void	remove_node(t_tree **node_ptr);
void	print_object_list(t_list *list);
#endif
