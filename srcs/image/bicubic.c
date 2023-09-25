/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bicubic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:41:20 by bena              #+#    #+#             */
/*   Updated: 2023/09/25 16:31:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "image.h"

static void		get_grid(t_pixel8 grid[4][4],
					float row, float column, t_image8 *source);
static void		bicubic_interpolate(t_pixel8 *target, t_pixel8 grid[4][4],
					float row, float column);
static float	get_cubic_convolution_weight(float distance);
static void		apply_weighted_sum(float buffer[4], t_pixel8 *pixel,
					float weight, int fianlize);

void	resize_image8(t_image8 *buffer, t_image8 *source)
{
	t_pixel8	grid[4][4];
	int			row;
	int			column;

	if (source == NULL || buffer == NULL
		|| source->size_height <= 0 || source->size_width <= 0
		|| buffer->size_height <= 0 || buffer->size_width <= 0)
		return ;
	row = 0;
	while (row < buffer->size_height)
	{
		column = 0;
		while (column < buffer->size_width)
		{
			get_grid(grid, (float)row / (float)buffer->size_height,
				(float)column / (float)buffer->size_width, source);
			bicubic_interpolate(buffer->data + get_index(row, column, buffer),
				grid, (float)row
				* (float)source->size_height / (float)buffer->size_height,
				(float)column
				* (float)source->size_width / (float)buffer->size_width);
			column++;
		}
		row++;
	}
}

static void	get_grid(t_pixel8 grid[4][4],
						float row, float column, t_image8 *source)
{
	const int	i_0 = (int)(row * source->size_height) - 1;
	const int	j_0 = (int)(column * source->size_width) - 1;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = source->data[get_index(i_0 + i, j_0 + j, source)];
			j++;
		}
		i++;
	}
}

static void	bicubic_interpolate(t_pixel8 *target, t_pixel8 grid[4][4],
								float row, float column)
{
	const float	row_decimal = row - (int)row;
	const float	column_decimal = column - (int)column;
	int			i;
	int			j;
	float		buffer[4];

	ft_memset(target, 0, sizeof(t_pixel8));
	ft_memset(buffer, 0, sizeof(buffer));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			apply_weighted_sum(buffer, &grid[i][j],
				get_cubic_convolution_weight(row_decimal + 1 - i)
				* get_cubic_convolution_weight(column_decimal + 1 - j),
				0);
			j++;
		}
		i++;
	}
	apply_weighted_sum(buffer, target, 0, 1);
}

static float	get_cubic_convolution_weight(float distance)
{
	const float	distance_sq = distance * distance;

	if (distance < 0)
		distance = -distance;
	if (distance < 1)
		return (
			1.5 * distance_sq * distance
			- 2.5 * distance_sq
			+ 1
		);
	else if (distance < 2)
		return (
			-0.5 * distance_sq * distance
			+ 2.5 * distance_sq
			- 4 * distance
			+ 2
		);
	return (0);
}

static void	apply_weighted_sum(float buffer[4], t_pixel8 *pixel,
								float weight, int finalize)
{
	int	i;

	if (finalize)
	{
		i = 0;
		while (i < 4)
		{
			if (buffer[i] < 0)
				buffer[i] = 0;
			if (buffer[i] > 255.01)
				buffer[i] = 255.01;
			i++;
		}
		pixel->transparency = (unsigned char)buffer[0];
		pixel->red = (unsigned char)buffer[1];
		pixel->green = (unsigned char)buffer[2];
		pixel->blue = (unsigned char)buffer[3];
		return ;
	}
	buffer[0] += pixel->transparency * weight;
	buffer[1] += pixel->red * weight;
	buffer[2] += pixel->green * weight;
	buffer[3] += pixel->blue * weight;
}
