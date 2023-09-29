/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_a_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:51:28 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 18:15:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"

void	*shoot_a_ray(t_vector buffer, t_ray ray, t_stat *stat)
{
	t_intersection	hitpoint;

	//hitpoint = get_intersection(&ray, stat->data);
	if (hitpoint.hit_object == M_HIT_NONE)
		return (vec_zero(buffer));
	//buffer = get_value_from_hitpoint(hitpoint);
	vec_product_scalar(buffer, buffer, ray.weight);
	return (buffer);
}
