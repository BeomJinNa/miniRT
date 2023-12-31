/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:21 by bena              #+#    #+#             */
/*   Updated: 2023/11/02 06:05:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "stat.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

static void	render_map_module(t_stat *stat);
static void	set_polar_coordinates_of_cam(t_cam *cam);
static void	get_a_pixel(t_stat *stat, t_real fov_unit, int i, int j);

void	render_map(t_stat *stat, t_real scale_factor)
{
	t_cam *const	cam = &stat->data.cam;

	cam->image.size_height = stat->win_height;
	cam->image.size_width = stat->win_width;
	ft_memset(cam->image.data, 0, cam->image.size_memory);
	if (0 < scale_factor && scale_factor < 1.0f)
	{
		cam->image.size_height = (int)(stat->win_height * scale_factor);
		cam->image.size_width = (int)(stat->win_width * scale_factor);
	}
	render_map_module(stat);
}

static void	render_map_module(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	const t_real	diagonal
		= hypotf(cam->image.size_height, cam->image.size_width);
	const t_real	fov_unit = cam->fov * (M_PI / 180.0) / diagonal;
	int				i;
	int				j;

	set_polar_coordinates_of_cam(cam);
	printf("rendering...\n\n");
	i = 0;
	while (i < cam->image.size_height)
	{
		j = 0;
		while (j < cam->image.size_width)
			get_a_pixel(stat, fov_unit, i, j++);
		i++;
	}
	printf("\033[Am\r                                                    \r");
	printf("Done!\n");
}

static void	set_polar_coordinates_of_cam(t_cam *cam)
{
	t_matrix	buffer1;
	t_matrix	buffer2;
	t_matrix	buffer3;

	if (is_real_zero(cam->normal_unit[0]) == 0
		|| is_real_zero(cam->normal_unit[1]) == 0)
		cam->spherical_theta = vec_get_polar_angle_theta(cam->normal_unit);
	cam->spherical_phi = vec_get_polar_angle_phi(cam->normal_unit);
	set_rotation_matrix_theta(cam->rotation,
		sinf(cam->spherical_theta), cosf(cam->spherical_theta));
	set_rotation_matrix_theta(buffer1,
		sinf(-cam->spherical_theta), cosf(-cam->spherical_theta));
	set_rotation_matrix_phi(buffer2,
		sinf(M_PI_2 - cam->spherical_phi), cosf(M_PI_2 - cam->spherical_phi));
	mat_product(buffer3, buffer2, buffer1);
	mat_product_vector(cam->buffer_direction, buffer3, cam->normal_unit);
}

static void	get_a_pixel(t_stat *stat, t_real fov_unit, int i, int j)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		direction;
	t_ray			ray;
	t_vector		convert;
	t_vector		temp;

	convert[0] = (((cam->image.size_width - 1) / 2.0f) - j) * fov_unit;
	convert[1] = (i - ((cam->image.size_height - 1) / 2.0f)) * fov_unit;
	get_converted_gyro_direction(temp,
		cam->buffer_direction, cam->spherical_phi, convert);
	mat_product_vector(direction, cam->rotation, temp);
	ray = set_ray(cam->position, direction, 1);
	if ((i * cam->image.size_width + j) % 65536 == 0)
	{
		printf("\033[Am\r                                                    \r");
		printf("\033[90m(%d/%d)\033[0m\n", i * cam->image.size_width + j,
			cam->image.size_width * cam->image.size_height);
	}
	shoot_a_ray(cam->image.data[i * cam->image.size_width + j],
		ray, &stat->data, 1);
}
