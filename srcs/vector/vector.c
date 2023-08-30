/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/08/30 08:56:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	sphere_to_vec(double vector[3], double theta, double phi)
{
	double	size;

	vector[0] = cos(theta) * sin(phi);
	vector[1] = sin(theta) * sin(phi);
	vector[2] = cos(phi);
	size = sqrt(vector[0] * vector[0] + vector[1] * vector[1]
			+ vector[2] * vector[2]);
	vector[0] /= size;
	vector[1] /= size;
	vector[2] /= size;
}

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

double	dot_product(double v1[3], double v2[3])
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

double	get_angular_coordinate(double p[3], double u[3], double h[3])
{
	const double	projection_to_u = dot_product(u, p);
	const double	projection_to_h = dot_product(h, p);

	return (
		acos(
			projection_to_u / hypot(projection_to_u, projection_to_h)
		)
	);
}
