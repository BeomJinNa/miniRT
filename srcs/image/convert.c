/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:38 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 20:49:07 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft.h"
#include <stdlib.h>

void	init_image8(t_image8 *image, int width, int height)
{
	const int	size = width * height;

	if (image == NULL)
		return ;
	image->data = (t_pixel8 *)malloc(sizeof(t_pixel8) * size);
	if (image->data == NULL)
		return ;
	ft_memset(image->data, 0, sizeof(t_pixel8) * size);
	image->size_width = width;
	image->size_height = height;
}

void	tone_map_to_pixel8(t_pixel8 *buffer, t_vector pixel)
{
	t_vector	temp;

	vec_product_scalar(temp, pixel, 255);
	vec_cutoff_max(temp, temp, 255.1);
	buffer->transparency = 0;
	buffer->red = (unsigned int)temp[0];
	buffer->green = (unsigned int)temp[1];
	buffer->blue = (unsigned int)temp[2];
}

void	tone_map_image(t_image8 *image, t_sensor *sensor)
{
	int	index;
	int	size;

	if (image->size_width != sensor->size_width
		|| image->size_height != sensor->size_height)
		return ;
	size = image->size_width * image->size_height;
	index = 0;
	while (index < size)
	{
		tone_map_to_pixel8(&image->data[index], sensor->data[index]);
		index++;
	}
}
