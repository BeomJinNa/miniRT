/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:01:41 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 06:29:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>

void	camera_rotate_up(t_stat *stat)
{
	static const t_real	angle_unit = M_CAMERA_ROTATION_ANGLE * M_PI / 180.0;
	t_cam *const		cam = &stat->data.cam;
	t_real				new_phi;

	if (cam->spherical_phi > angle_unit)
		new_phi = cam->spherical_phi - angle_unit;
	else
		new_phi = 0;
	get_new_unit_vector_by_polar(cam->normal_unit,
		cam->spherical_theta, new_phi);
	re_render_image_on_mlx(stat);
}

void	camera_rotate_down(t_stat *stat)
{
	static const t_real	angle_unit = M_CAMERA_ROTATION_ANGLE * M_PI / 180.0;
	t_cam *const		cam = &stat->data.cam;
	t_real				new_phi;

	if (cam->spherical_phi < M_PI - angle_unit)
		new_phi = cam->spherical_phi + angle_unit;
	else
		new_phi = M_PI;
	get_new_unit_vector_by_polar(cam->normal_unit,
		cam->spherical_theta, new_phi);
	re_render_image_on_mlx(stat);
}

void	camera_rotate_left(t_stat *stat)
{
	static const t_real	angle_unit = M_CAMERA_ROTATION_ANGLE * M_PI / 180.0;
	t_cam *const		cam = &stat->data.cam;
	t_real				new_theta;

	new_theta = cam->spherical_theta + angle_unit;
	get_new_unit_vector_by_polar(cam->normal_unit,
		new_theta, cam->spherical_phi);
	re_render_image_on_mlx(stat);
}

void	camera_rotate_right(t_stat *stat)
{
	static const t_real	angle_unit = M_CAMERA_ROTATION_ANGLE * M_PI / 180.0;
	t_cam *const		cam = &stat->data.cam;
	t_real				new_theta;

	new_theta = cam->spherical_theta - angle_unit;
	get_new_unit_vector_by_polar(cam->normal_unit,
		new_theta, cam->spherical_phi);
	re_render_image_on_mlx(stat);
}
