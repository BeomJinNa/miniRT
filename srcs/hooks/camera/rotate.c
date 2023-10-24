/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:01:41 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 02:36:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>

void	camera_rotate_up(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_real			new_phi;

	if (cam->spherical_phi > M_CAMERA_ROTATION_ANGLE)
		new_phi = cam->spherical_phi - M_CAMERA_ROTATION_ANGLE;
	else
		new_phi = 0;
	get_new_unit_vector_by_polar(cam->normal_unit,
		cam->spherical_theta, new_phi);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}

void	camera_rotate_down(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_real			new_phi;

	if (cam->spherical_phi < M_PI - M_CAMERA_ROTATION_ANGLE)
		new_phi = cam->spherical_phi + M_CAMERA_ROTATION_ANGLE;
	else
		new_phi = M_PI;
	get_new_unit_vector_by_polar(cam->normal_unit,
		cam->spherical_theta, new_phi);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}

void	camera_rotate_left(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_real			new_theta;
	const t_real	one_cycle = M_PI * 2.0;

	new_theta = cam->spherical_theta + M_CAMERA_ROTATION_ANGLE;
	if (new_theta < 0)
		new_theta += one_cycle;
	else if (new_theta >= one_cycle)
		new_theta -= one_cycle;
	get_new_unit_vector_by_polar(cam->normal_unit,
		new_theta, cam->spherical_phi);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}

void	camera_rotate_right(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_real			new_theta;
	const t_real	one_cycle = M_PI * 2.0;

	new_theta = cam->spherical_theta - M_CAMERA_ROTATION_ANGLE;
	if (new_theta < 0)
		new_theta += one_cycle;
	else if (new_theta >= one_cycle)
		new_theta -= one_cycle;
	get_new_unit_vector_by_polar(cam->normal_unit,
		new_theta, cam->spherical_phi);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}
