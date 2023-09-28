/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:34:51 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 19:20:24 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>

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
