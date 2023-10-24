/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:53:28 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 01:53:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "image.h"
# include "s_list.h"

# define M_OBJECT_PLANE_DEFAULT_RADIUS 1000.0

typedef struct s_object	t_object;

enum e_object_type
{
	M_OBJECT_TYPE_NONE		= 0,
	M_OBJECT_TYPE_PLANE		= 1,
	M_OBJECT_TYPE_SPHERE	= 2,
	M_OBJECT_TYPE_CYLINDER	= 3,
	M_OBJECT_TYPE_CONE		= 4,
};

enum e_object_marker
{
	M_OBJECT_MARK_INIT			= -1,
	M_OBJECT_MARK_NOMARK		= 0,
	M_OBJECT_MARK_FRONT_GROUP	= 1,
	M_OBJECT_MARK_BACK_GROUP	= 2,
};

enum e_texture_flags
{
	FLAG_TEXTURE_IMAGE	= 1 << 0,
	FLAG_TEXTURE_BUMP	= 1 << 1,
};

enum e_plane_flags
{
	FLAG_BV_REGION_X		= 1 << 0,
	FLAG_BV_REGION_Y		= 1 << 1,
	FLAG_BV_REGION_Z		= 1 << 2,
	FLAG_BV_REGION_X_BOTTOM	= 1 << 3,
	FLAG_BV_REGION_X_TOP	= 1 << 4,
	FLAG_BV_REGION_Y_BOTTOM	= 1 << 5,
	FLAG_BV_REGION_Y_TOP	= 1 << 6,
	FLAG_BV_REGION_Z_BOTTOM	= 1 << 7,
	FLAG_BV_REGION_Z_TOP	= 1 << 8,
};

typedef struct s_cam
{
	t_vector	position;
	t_vector	normal_unit;
	t_real		spherical_theta;
	t_real		spherical_phi;
	t_real		fov;
	t_sensor	image;
}	t_cam;

typedef struct s_light
{
	t_vector	position;
	t_vector	color;
}	t_light;

typedef struct s_texture
{
	t_vector	reflectance;
	t_vector	transmittance;
	t_image8	image;
	t_image8	bump;
	int			flags;
	t_real		reflection_ratio;
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

struct s_object
{
	int			type;
	t_bv		bv;
	int			marker;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
	}	u_data;
	t_texture	texture;
};

int		init_sphere(t_object *object, t_vector position, t_real radius);
int		init_plane(t_object *object, t_vector position,
			t_vector normal, t_real radius);
int		init_cylinder(t_object *object, t_vector position,
			t_vector normal, t_real radius);
int		init_cone(t_object *object, t_vector position,
			t_vector normal, t_real radius);
void	init_bounding_volume(t_bv *bv);
void	get_integrated_bounding_volume(t_bv *buffer, t_list *object_list);
void	update_min_max_boundary(t_bv *buffer, t_bv *target);
int		is_point_in_bv(t_vector position, t_bv *bv);
int		is_point_in_plane_bv(t_vector point, t_bv *bv, int axis1, int axis2);
int		get_flag_region_info(t_vector point, t_bv *bv);
void	*move_point_onto_plane(t_vector point, t_vector normal_unit,
			t_real position, int axis);
t_list	*listdup(t_list *list);
void	print_object_info_in_one_line(void *object);
#endif
