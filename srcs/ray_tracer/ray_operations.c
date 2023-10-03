/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:27:13 by bena              #+#    #+#             */
/*   Updated: 2023/10/06 10:56:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/*
 * Caution! Use only UNIT VECTORS in arguments (vectors of size 1)
 */
void	*get_reflected_ray(t_vector buffer, t_vector ray_normal_unit,
			t_vector surface_normal_unit)
{
	t_vector	reflection_normal2;

	vec_product_scalar(reflection_normal2, surface_normal_unit,
		-2 * vec_dot_product(ray_normal_unit, surface_normal_unit));
	vec_add(buffer, ray_normal_unit, reflection_normal2);
	return (buffer);
}
