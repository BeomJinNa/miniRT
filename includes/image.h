/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:42:53 by bena              #+#    #+#             */
/*   Updated: 2023/09/12 11:19:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_pixel_8bit
{
	unsigned char	transparency;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_pixel8;

typedef struct s_image_8bit
{
	unsigned int	size_width;
	unsigned int	size_height;
	t_pixel8		*data;
}	t_image8;

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
#endif
