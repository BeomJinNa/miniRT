/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:56:27 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 18:50:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stdio.h>

static void	print_object_info_in_one_line2(void *object);

void	print_object_info_in_one_line(void *object)
{
	t_object *const		ptr = (t_object *)object;
	t_plane *const		pl = &ptr->u_data.plane;
	t_vector			cl;

	vec_product_scalar(cl, ptr->texture.reflectance, 255);
	printf("\033[36m[OBJECT] \033[33mType: \033[0m");
	if (ptr->type == M_OBJECT_TYPE_PLANE)
		printf("Plane");
	else if (ptr->type == M_OBJECT_TYPE_SPHERE)
		printf("Sphere");
	else if (ptr->type == M_OBJECT_TYPE_CYLINDER)
		printf("Cylinder");
	else if (ptr->type == M_OBJECT_TYPE_CONE)
		printf("Cone");
	printf("\t\033[38;2;%d;%d;%dm(RGB: %03d, %03d, %03d)\033[90m"
		" | reflection ratio %.2f",
		(int)cl[0], (int)cl[1], (int)cl[2], (int)cl[0], (int)cl[1], (int)cl[2],
		ptr->texture.reflection_ratio);
	if (ptr->type == M_OBJECT_TYPE_PLANE)
		printf(" | Position (%+4.2f, %+4.2f, %+4.2f) | Radius %.3f | Direction "
			"(%+5.2f, %+5.2f, %+5.2f)", pl->position[0], pl->position[1],
			pl->position[2], pl->radius, pl->normal_unit[0], pl->normal_unit[1],
			pl->normal_unit[2]);
	print_object_info_in_one_line2(object);
}

static void	print_object_info_in_one_line2(void *object)
{
	t_object *const		ptr = (t_object *)object;
	t_sphere *const		sp = &ptr->u_data.sphere;
	t_cylinder *const	cy = &ptr->u_data.cylinder;
	t_cone *const		cn = &ptr->u_data.cone;

	if (ptr->type == M_OBJECT_TYPE_SPHERE)
		printf(" | Position (%+4.2f, %+4.2f, %+4.2f) | Radius %.3f",
			sp->position[0], sp->position[1], sp->position[2], sp->radius);
	else if (ptr->type == M_OBJECT_TYPE_CYLINDER)
		printf(" | Position (%+4.2f, %+4.2f, %+4.2f) | Radius %.3f | Direction "
			"(%+5.2f, %+5.2f, %+5.2f) | Height %f", cy->position[0],
			cy->position[1], cy->position[2], cy->radius, cy->normal_unit[0],
			cy->normal_unit[1], cy->normal_unit[2], cy->height);
	else if (ptr->type == M_OBJECT_TYPE_CONE)
		printf(" | Position (%+4.2f, %+4.2f, %+4.2f) | Radius %.3f | Direction "
			"(%+5.2f, %+5.2f, %+5.2f) | Height %f", cn->position[0],
			cn->position[1], cn->position[2], cn->radius, cn->normal_unit[0],
			cn->normal_unit[1], cn->normal_unit[2], cn->height);
	printf("\033[0m\n");
}
