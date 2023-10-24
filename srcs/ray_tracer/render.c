/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:21 by bena              #+#    #+#             */
/*   Updated: 2023/10/24 23:46:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "stat.h"
#include <math.h>
#include <stdio.h>

static void	get_a_pixel(t_stat *stat, t_real fov_unit, int i, int j);

void	render_map(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	const t_real	diagonal
		= hypotf(cam->image.size_height, cam->image.size_width);
	const t_real	fov_unit = cam->fov * (M_PI / 180.0) / diagonal;
	int				i;
	int				j;

	cam->spherical_theta = vec_get_polar_angle_theta(cam->normal_unit);
	cam->spherical_phi = vec_get_polar_angle_phi(cam->normal_unit);
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

static void	get_a_pixel(t_stat *stat, t_real fov_unit, int i, int j)
{
	t_cam *const	cam = &stat->data.cam;
	t_vector		direction;
	t_ray			ray;
	t_real			pixel_theta;
	t_real			pixel_phi;

	pixel_theta = cam->spherical_theta
		+ (((cam->image.size_width - 1) / 2.0f) - j) * fov_unit;
	pixel_phi = cam->spherical_phi
		+ (i - ((cam->image.size_height - 1) / 2.0f)) * fov_unit;
	get_new_unit_vector_by_polar(direction, pixel_theta, pixel_phi);
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
