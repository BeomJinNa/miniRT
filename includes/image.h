/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:42:53 by bena              #+#    #+#             */
/*   Updated: 2023/09/25 15:37:14 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "vector.h"

typedef struct s_pixel_8bit
{
	unsigned char	transparency;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_pixel8;

typedef struct s_image_8bit
{
	int			size_width;
	int			size_height;
	t_pixel8	*data;
}	t_image8;

typedef struct s_sensor
{
	int		size_width;
	int		size_height;
	vector	*data;
}	t_sensor;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	img_mlx_pixel_put(t_img *data, int x, int y, int color);
void	get_image_address(t_img *img);
int		get_index(int row, int column, t_image8 *image);
void	resize_image8(t_image8 *buffer, t_image8 *source);
#endif
