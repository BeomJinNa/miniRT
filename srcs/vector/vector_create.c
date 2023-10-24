/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:02:27 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 01:37:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

void	get_new_unit_vector_by_polar(t_vector buffer, t_real theta, t_real phi)
{
	buffer[0] = cosf(theta) * sinf(phi);
	buffer[1] = sinf(theta) * sinf(phi);
	buffer[2] = cosf(phi);
	if (phi < 0)
	{
		buffer[0] = -buffer[0];
		buffer[1] = -buffer[1];
	}
}

void	get_horizontal_
void	get_horizontal_unit(double h_unit[3], double theta)
{
	h_unit[0] = sin(theta);
	h_unit[1] = -cos(theta);
	h_unit[2] = 0;
}

void	get_vertical_unit(double v_unit[3], double vec[3], double h_unit[3])
{
	double	size;

	v_unit[0] = vec[1] * h_unit[2] - (h_unit[1] * vec[2]);
	v_unit[1] = h_unit[0] * vec[2] - (vec[0] * h_unit[2]);
	v_unit[2] = vec[0] * h_unit[1] - (h_unit[0] * vec[1]);
	size = sqrt(v_unit[0] * v_unit[0] + v_unit[1] * v_unit[1]
			+ v_unit[2] * v_unit[2]);
	v_unit[0] /= size;
	v_unit[1] /= size;
	v_unit[2] /= size;
}
