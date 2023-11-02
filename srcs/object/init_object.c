/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:53:36 by bena              #+#    #+#             */
/*   Updated: 2023/11/02 19:02:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stat.h"

void	set_bv_on_plane(t_object *plane);
void	set_bv_on_cylinder(t_object *cylinder);
void	set_bv_on_cone(t_object *cone);

/*
 * If initialization failed, return 1
 */
int	init_sphere(t_object *object, t_vector position, t_real radius)
{
	if (object == NULL || position == NULL || radius <= 0)
		return (1);
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_SPHERE;
	vec_copy(object->u_data.sphere.position, position);
	object->u_data.sphere.radius = radius;
	vec_add_scalar(object->bv.max, position, radius);
	vec_subtract_scalar(object->bv.min, position, radius);
	object->texture.reflection_ratio = M_DEFAULT_REFLECTION_RATIO;
	object->marker = M_OBJECT_MARK_INIT;
	return (0);
}

int	init_plane(t_object *object, t_vector position,
			t_vector normal, t_real radius)
{
	if (object == NULL || position == NULL
		|| normal == NULL || is_vector_zero(normal))
		return (1);
	radius = M_OBJECT_PLANE_DEFAULT_RADIUS;
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_PLANE;
	vec_copy(object->u_data.plane.position, position);
	vec_copy(object->u_data.plane.normal, normal);
	vec_divide_scalar(object->u_data.plane.normal_unit,
		normal, vec_size(normal));
	object->u_data.plane.radius = radius;
	object->texture.reflection_ratio = M_PLANE_REFLECTION_RATIO;
	object->marker = M_OBJECT_MARK_INIT;
	set_bv_on_plane(object);
	return (0);
}

int	init_cylinder(t_object *object, t_vector position,
			t_vector normal, t_real radius)
{
	if (object == NULL || position == NULL
		|| normal == NULL || is_vector_zero(normal) || radius <= 0)
		return (1);
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_CYLINDER;
	vec_copy(object->u_data.cylinder.position, position);
	vec_copy(object->u_data.cylinder.normal, normal);
	object->u_data.cylinder.radius = radius;
	object->u_data.cylinder.height = vec_size(normal);
	vec_divide_scalar(object->u_data.cylinder.normal_unit,
		normal, object->u_data.cylinder.height);
	object->texture.reflection_ratio = M_DEFAULT_REFLECTION_RATIO;
	object->marker = M_OBJECT_MARK_INIT;
	set_bv_on_cylinder(object);
	return (0);
}

int	init_cone(t_object *object, t_vector position,
			t_vector normal, t_real radius)
{
	if (object == NULL || position == NULL
		|| normal == NULL || is_vector_zero(normal) || radius <= 0)
		return (1);
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_CONE;
	vec_copy(object->u_data.cone.position, position);
	vec_copy(object->u_data.cone.normal, normal);
	object->u_data.cone.radius = radius;
	object->u_data.cone.height = vec_size(normal);
	vec_divide_scalar(object->u_data.cone.normal_unit,
		normal, object->u_data.cone.height);
	object->texture.reflection_ratio = M_DEFAULT_REFLECTION_RATIO;
	object->marker = M_OBJECT_MARK_INIT;
	set_bv_on_cone(object);
	return (0);
}
