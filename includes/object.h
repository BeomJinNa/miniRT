/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:53:28 by bena              #+#    #+#             */
/*   Updated: 2023/09/27 12:38:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "image.h"
# include "s_list.h"

enum e_object_type
{
	M_OBJECT_TYPE_PLANE = 0,
	M_OBJECT_TYPE_SPHERE = 1,
	M_OBJECT_TYPE_CYLINDER = 2,
	M_OBJECT_TYPE_CONE = 3
};

enum e_texture_flags
{
	FLAG_TEXTURE_IMAGE = 1 << 0,
	FLAG_TEXTURE_BUMP = 1 << 1
};

typedef struct s_texture
{
	t_pixel8	color;
	t_image8	image;
	t_image8	bump;
	int			flags;
}	t_texture;

typedef struct s_sphere
{
	t_vector	position;
	t_real		radius;
}	t_sphere;

typedef struct s_plane
{
	t_vector	position;
	t_vector	normal;
	t_vector	normal_unit;
	t_real		radius;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	normal;
	t_vector	normal_unit;
	t_real		height;
	t_real		radius;
}	t_cylinder;

typedef struct s_cone
{
	t_vector	position;
	t_vector	normal;
	t_vector	normal_unit;
	t_real		height;
	t_real		radius;
}	t_cone;

typedef struct s_bounding_volume
{
	t_vector	min;
	t_vector	max;
}	t_bv;

typedef struct s_object
{
	int			type;
	t_bv		bv;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
	}	u_data;
	t_texture	texture;
}	t_object;

void	init_sphere(t_object *object, t_vector position, t_real radius);
void	init_plane(t_object *object, t_vector position,
			t_vector normal, t_real radius);
void	init_cylinder(t_object *object, t_vector position,
			t_vector normal, t_real radius);
void	init_cone(t_object *object, t_vector position,
			t_vector normal, t_real radius);
void	init_bounding_volume(t_bv *bv);
void	get_integrated_bounding_volume(t_bv *buffer, t_list *object_list);
void	update_min_max_boundary(t_bv *buffer, t_bv *target);
#endif
