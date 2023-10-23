/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:23:16 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 20:38:23 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include <mlx.h>

void	img_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	img_mlx_image_put(t_img *data, t_image8 *image)
{
	const int	size = image->size_height * image->size_width;
	int			index;

	index = 0;
	while (index < size)
	{
		*((unsigned int *)data->addr + index)
			= *((unsigned int *)&image->data[index]);
		index++;
	}
}

void	get_image_address(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	get_index(int row, int column, t_image8 *image)
{
	if (row < 0)
		row = 0;
	if (row >= image->size_height)
		row = image->size_height - 1;
	if (column < 0)
		column = 0;
	if (column >= image->size_width)
		column = image->size_width - 1;
	return (row * image->size_width + column);
}
