/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:58:38 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 19:01:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include <stdio.h>

static void	print_cam(t_cam *cam);
static void	print_lights(void *lights);

void	print_data(t_data *data)
{
	printf("\033[33mINFORMATION\033[0m\n\n");
	print_cam(&data->cam);
	ft_lstiter(data->lights, print_lights);
	print_tree(data->tree);
	printf("========================================"
		"========================================\n");
}

static void	print_cam(t_cam *cam)
{
	printf("\033[32mCAMERA\033[0m\n"
		"position : \033[90m(%.2f, %.2f, %.2f)\033[0m\n"
		"direction : \033[90m(%.2f, %.2f, %.2f)\033[0m\n"
		"field of view(fov) : \033[90m%f (degrees)\033[0m\n",
		cam->position[0], cam->position[1], cam->position[2],
		cam->normal_unit[0], cam->normal_unit[1], cam->normal_unit[2],
		cam->fov);
}

static void	print_lights(void *lights)
{
	t_light *const	ptr = (t_light *)lights;

	printf("\033[32mSPOT LIGHT\033[0m\n"
		"position : \033[90m(%.2f, %.2f, %.2f)\033[0m\n"
		"red : \033[90m%.1f\033[0m\n"
		"green : \033[90m%.1f\033[0m\n"
		"blue : \033[90m%.1f\033[0m\n",
		ptr->position[0], ptr->position[1], ptr->position[2],
		ptr->color[0], ptr->color[1], ptr->color[2]);
}
