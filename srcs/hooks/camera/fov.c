/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:15:55 by bena              #+#    #+#             */
/*   Updated: 2023/11/02 19:02:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"

void	zoom_out(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	cam->fov *= M_CAMERA_FOV_SCALE_SENSITIVITY;
	if (cam->fov > M_CAMERA_MAX_FOV)
		cam->fov = M_CAMERA_MAX_FOV;
	re_render_image_on_mlx(stat);
}

void	zoom_in(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	cam->fov /= M_CAMERA_FOV_SCALE_SENSITIVITY;
	if (cam->fov < M_CAMERA_MIN_FOV)
		cam->fov = M_CAMERA_MIN_FOV;
	re_render_image_on_mlx(stat);
}
