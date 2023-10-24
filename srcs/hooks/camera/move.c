/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:01:41 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 04:10:23 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>

void	camera_move_forward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	vec_add(cam->position, cam->position, cam->normal_unit);
	re_render_image_on_mlx(stat);
}

void	camera_move_backward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	vec_subtract(cam->position, cam->position, cam->normal_unit);
	re_render_image_on_mlx(stat);
}

void	camera_move_leftward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	get_new_unit_vector_by_polar(shift, cam->spherical_theta + M_PI_2, M_PI_2);
	vec_add(cam->position, cam->position, shift);
	re_render_image_on_mlx(stat);
}

void	camera_move_rightward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	get_new_unit_vector_by_polar(shift, cam->spherical_theta + M_PI_2, M_PI_2);
	vec_subtract(cam->position, cam->position, shift);
	re_render_image_on_mlx(stat);
}
