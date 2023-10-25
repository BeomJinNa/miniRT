/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exposure.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:15:55 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 09:05:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>

void	increase_exposure(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	cam->image.exposure *= M_SQRT2;
	if (cam->image.exposure > M_EXPOSURE_MAX)
		cam->image.exposure = M_EXPOSURE_MAX;
	re_draw_image_on_mlx(stat);
}

void	decrease_exposure(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;

	cam->image.exposure *= M_SQRT1_2;
	if (cam->image.exposure < M_EXPOSURE_MIN)
		cam->image.exposure = M_EXPOSURE_MIN;
	re_draw_image_on_mlx(stat);
}
