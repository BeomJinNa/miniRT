/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:34:51 by bena              #+#    #+#             */
/*   Updated: 2023/09/22 03:24:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

t_tree	*init_tree(t_list *obj_list)
{
	t_tree	*output;

	if (obj_list == NULL)
		return (NULL);
	output = (t_tree *)malloc(sizeof(t_tree));
	if (output == NULL)
		return (NULL);
	output->objects = obj_list;
	if (output->objects == NULL)
	{
		free(output);
		return (NULL);
	}
	output->parent = NULL;
	output->left = NULL;
	output->right = NULL;
	output->axis = -1;
	return (output);
}
