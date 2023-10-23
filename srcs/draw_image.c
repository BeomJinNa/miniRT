/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:04:31 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 20:43:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "mlx.h"
#include <stdlib.h>

int			close_window(t_stat *stat);
static void	malloc_failed(t_stat *stat, t_img *image, void *data);

void	draw_image(t_stat *stat)
{
	t_sensor *const	cam = &stat->data.cam.image;
	t_image8		clone;
	t_image8		buffer;
	t_img			image;

	image.img = mlx_new_image(stat->mlx, stat->win_width, stat->win_height);
	if (image.img == NULL)
		close_window(stat);
	init_image8(&clone, cam->size_width, cam->size_height);
	if (clone.data == NULL)
		malloc_failed(stat, &image, NULL);
	init_image8(&buffer, stat->win_width, stat->win_height);
	if (buffer.data == NULL)
		malloc_failed(stat, &image, clone.data);
	get_image_address(&image);
	tone_map_image(&clone, cam);
	resize_image8(&buffer, &clone);
	img_mlx_image_put(&image, &buffer);
	mlx_put_image_to_window(stat->mlx, stat->win, image.img, 0, 0);
	mlx_destroy_image(stat->mlx, image.img);
	free(clone.data);
	free(buffer.data);
}

static void	malloc_failed(t_stat *stat, t_img *image, void *data)
{
	if (image != NULL)
		mlx_destroy_image(stat->mlx, image->img);
	if (data != NULL)
		free(data);
	close_window(stat);
}
