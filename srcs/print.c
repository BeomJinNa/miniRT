/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:58:38 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 13:05:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include <stdio.h>

static void	print_cam(t_cam *cam);
static void	print_lights(void *lights);

void	print_data(t_data *data)
{
	printf("INFORMATION miniRT\n\n");
	print_cam(&data->cam);
	ft_lstiter(data->lights, print_lights);
	//print_images(data->images);
	print_tree(data->tree);
}

static void	print_cam(t_cam *cam)
{
	printf("CAMERA\n"
		"position : (%.2f, %.2f, %.2f)\n"
		"direction : (%.2f, %.2f, %.2f)\n"
		"field of view(fov) : %f (degrees)\n",
		cam->position[0], cam->position[1], cam->position[2],
		cam->normal_unit[0], cam->normal_unit[1], cam->normal_unit[2],
		cam->fov);
}

static void	print_lights(void *lights)
{
	t_light *const	ptr = (t_light *)lights;

	printf("SPOT LIGHT\n"
		"position : (%.2f, %.2f, %.2f)\n"
		"red : %.1f\n"
		"green : %.1f\n"
		"blue : %.1f\n",
		ptr->position[0], ptr->position[1], ptr->position[2],
		ptr->color[0], ptr->color[1], ptr->color[2]);
}
