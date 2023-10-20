/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:55:13 by bena              #+#    #+#             */
/*   Updated: 2023/10/20 20:43:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "object.h"
# include "s_ray.h"

typedef struct s_tree	t_tree;

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

/*
 * Traverse the k-d tree and apply the given function `f` to objects that
 * intersect with the ray. The function `f` is invoked with the object and
 * the `arg` parameter from `traverse_tree` as its arguments.
 */
void	traverse_tree(t_tree *tree, t_ray *ray,
			void (*f)(t_object *, void *), void *arg);
int		is_bv_in_raypath(t_ray *ray, t_bv *bv);
#endif
