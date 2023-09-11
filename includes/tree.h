/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:55:13 by bena              #+#    #+#             */
/*   Updated: 2023/09/11 22:51:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "object.h"
# include "s_list.h"

typedef struct s_tree	t_tree;

enum	e_axis_type
{
	M_AXIS_X = 0,
	M_AXIS_Y = 1,
	M_AXIS_Z = 2
};

struct s_tree
{
	t_tree		*parent;
	t_tree		*left;
	t_tree		*right;
	t_list		*objects;
	int			axis;
};
#endif
