/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:01:41 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 02:13:40 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>

void	camera_move_forward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	vec_add(cam->position, cam->position, cam->normal_unit);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}

void	camera_move_backward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	vec_subtract(cam->position, cam->position, cam->normal_unit);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}

void	camera_move_leftside(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	get_new_unit_vector_by_polar(shift, cam->spherical_theta + M_PI_2, 0);
	vec_add(cam->position, cam->position, shift);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}

void	camera_move_rightside(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	get_new_unit_vector_by_polar(shift, cam->spherical_theta + M_PI_2, 0);
	vec_subtract(cam->position, cam->position, shift);
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
}
