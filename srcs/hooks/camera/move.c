/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:01:41 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 06:55:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>

void	camera_move_forward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	vec_product_scalar(shift, cam->normal_unit, M_MOVING_DISTANCE);
	vec_add(cam->position, cam->position, shift);
	re_render_image_on_mlx(stat);
}

void	camera_move_backward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	vec_product_scalar(shift, cam->normal_unit, M_MOVING_DISTANCE);
	vec_subtract(cam->position, cam->position, shift);
	re_render_image_on_mlx(stat);
}

void	camera_move_leftward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	get_new_unit_vector_by_polar(shift, cam->spherical_theta + M_PI_2, M_PI_2);
	vec_product_scalar(shift, shift, M_MOVING_DISTANCE);
	vec_add(cam->position, cam->position, shift);
	re_render_image_on_mlx(stat);
}

void	camera_move_rightward(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		shift;

	get_new_unit_vector_by_polar(shift, cam->spherical_theta + M_PI_2, M_PI_2);
	vec_product_scalar(shift, shift, M_MOVING_DISTANCE);
	vec_subtract(cam->position, cam->position, shift);
	re_render_image_on_mlx(stat);
}
