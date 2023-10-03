/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:35:24 by bena              #+#    #+#             */
/*   Updated: 2023/10/06 08:47:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	is_point_in_plane(t_vector point_position, t_vector plane_position,
			t_vector plane_normal)
{
	t_vector	displacement;

	vec_subtract(displacement, plane_position, point_position);
	if (is_real_zero(vec_dot_product(displacement, plane_normal)))
		return (1);
	return (0);
}
