/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:53:28 by bena              #+#    #+#             */
/*   Updated: 2023/09/12 12:19:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "image.h"

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
	vector	position;
	float	radius;
}	t_sphere;

typedef struct s_plane
{
	vector	position;
	vector	normal;
}	t_plane;

typedef struct s_cylinder
{
	vector	position;
	vector	normal;
	float	height;
	float	radius;
}	t_cylinder;

typedef struct s_cone
{
	vector	position;
	vector	normal;
	float	height;
	float	radius;
}	t_cone;

typedef struct s_bounding_volume
{
	vector	min;
	vector	max;
}	t_bv;

typedef struct s_object
{
	int			type;
	t_bv		bv;
	union		u_data
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
	};
	t_texture	texture;
}	t_object;
#endif
