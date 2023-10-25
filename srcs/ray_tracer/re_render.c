/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:08:15 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 09:33:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <stdio.h>

void	re_render_image_on_mlx(t_stat *stat)
{
	delete_cam_info();
	render_map(stat, M_DEFAULT_PREVIEW_SCALE);
	draw_image(stat);
	print_cam_info(stat);
}

void	render_hires_image_on_mlx(t_stat *stat)
{
	delete_cam_info();
	render_map(stat, 1.0f);
	draw_image(stat);
	print_cam_info(stat);
}

void	re_draw_image_on_mlx(t_stat *stat)
{
	delete_cam_info();
	printf("drawing...\n");
	draw_image(stat);
	printf("Done!\n");
	print_cam_info(stat);
}
