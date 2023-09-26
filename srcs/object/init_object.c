/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:53:36 by bena              #+#    #+#             */
/*   Updated: 2023/09/26 22:41:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "set_bv.h"

void	init_sphere(t_object *object, t_vector position, t_real radius)
{
	if (object == NULL || position == NULL || radius <= 0)
		return ;
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_SPHERE;
	vec_copy(object->u_data.sphere.position, position);
	object->u_data.sphere.radius = radius;
	vec_add_elem(object->bv.max, position, radius);
	vec_subtract_elem(object->bv.min, position, radius);
}

void	init_plane(t_object *object, t_vector position, t_vector normal, t_real radius)
{
	if (object == NULL || position == NULL || normal == NULL || radius <= 0)
		return ;
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_PLANE;
	vec_copy(object->u_data.plane.position, position);
	vec_copy(object->u_data.plane.normal, normal);
	object->u_data.plane.radius = radius;
	set_bv_on_plane(object);
}

void	init_cylinder(t_object *object, t_vector position, t_vector normal, t_real radius)
{
	if (object == NULL || position == NULL || normal == NULL || radius <= 0)
		return ;
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_CYLINDER;
	vec_copy(object->u_data.cylinder.position, position);
	vec_copy(object->u_data.cylinder.normal, normal);
	object->u_data.cylinder.radius = radius;
	object->u_data.cylinder.height = vec_size(normal);
	set_bv_on_cylinder(object);
}

void	init_cone(t_object *object, t_vector position, t_vector normal, t_real radius)
{
	if (object == NULL || position == NULL || normal == NULL || radius <= 0)
		return ;
	ft_memset(object, 0, sizeof(t_object));
	object->type = M_OBJECT_TYPE_CONE;
	vec_copy(object->u_data.cone.position, position);
	vec_copy(object->u_data.cone.normal, normal);
	object->u_data.cone.radius = radius;
	object->u_data.cone.height = vec_size(normal);
	set_bv_on_cone(object);
}