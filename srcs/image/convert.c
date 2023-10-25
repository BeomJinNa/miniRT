/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:38 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 09:21:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "image.h"
#include <stdlib.h>

static t_real	get_exposure(t_sensor *sensor, int size);

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

void	tone_map_to_pixel8(t_pixel8 *buffer, t_vector pixel, t_real multiply)
{
	t_vector	temp;

	vec_product_scalar(temp, pixel, multiply);
	vec_cutoff_max(temp, temp, 255.1);
	buffer->transparency = (unsigned char)0;
	buffer->red = (unsigned char)temp[0];
	buffer->green = (unsigned char)temp[1];
	buffer->blue = (unsigned char)temp[2];
}

void	tone_map_image(t_image8 *image, t_sensor *sensor)
{
	int		index;
	int		size;
	t_real	multiply;

	if (image->size_width != sensor->size_width
		|| image->size_height != sensor->size_height)
		return ;
	size = image->size_width * image->size_height;
	multiply = get_exposure(sensor, size);
	multiply = sensor->exposure * 255.0 / multiply;
	index = 0;
	while (index < size)
	{
		tone_map_to_pixel8(&image->data[index], sensor->data[index], multiply);
		index++;
	}
}

static t_real	get_exposure(t_sensor *sensor, int size)
{
	int		index;
	t_real	output;

	output = 0.0001f;
	index = 0;
	while (index < size)
	{
		if (output < sensor->data[index][0])
			output = sensor->data[index][0];
		if (output < sensor->data[index][1])
			output = sensor->data[index][1];
		if (output < sensor->data[index][2])
			output = sensor->data[index][2];
		index++;
	}
	return (output);
}

int	trgb_from_pixel8(t_pixel8 *pixel)
{
	return (
		(pixel->transparency << 24)
		| (pixel->red << 16)
		| (pixel->green << 8)
		| pixel->blue
	);
}
