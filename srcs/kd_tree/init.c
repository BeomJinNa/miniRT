/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:34:51 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 17:50:21 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>

/*
 * Caution!!!
 *
 * This function destroys obj_list entered as an argument. Use a copied list.
 * It will not destroy the objects in the list, but the list will be destroyed.
 */
t_tree	*init_tree(t_list *obj_list)
{
	t_tree	*output;

	if (obj_list == NULL)
		return (NULL);
	output = (t_tree *)malloc(sizeof(t_tree));
	if (output == NULL)
		return (NULL);
	output->parent = NULL;
	output->left = NULL;
	output->right = NULL;
	output->axis = -1;
	output->objects = obj_list;
	init_bounding_volume(&output->bv);
	return (output);
}
