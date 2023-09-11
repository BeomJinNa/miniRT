/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:53:28 by bena              #+#    #+#             */
/*   Updated: 2023/09/11 22:31:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

enum e_object_type
{
	M_OBJECT_TYPE_PLANE = 0,
	M_OBJECT_TYPE_SPHERE = 1,
	M_OBJECT_TYPE_CYLINDER = 2,
	M_OBJECT_TYPE_CONE = 3
};

typedef struct s_plane
{
}t_plane;

typedef struct s_sphere
{
}t_sphere;

typedef struct s_cylinder
{
}t_cylinder;

typedef struct s_cone
{
}t_cone;

typedef union u_obj_data
{
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_cone		cone;
}				t_obj_data;

typedef struct s_bounding_volume
{
	vector	min;
	vector	max;
}			t_bv;

typedef struct s_object
{
	int			type;
	t_bv		bv;
	t_obj_data	data;
}				t_object;
#endif
