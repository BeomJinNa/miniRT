/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:58:38 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 10:36:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include <stdio.h>

static void	print_cam(t_cam *cam);
static void	print_ambient(t_vector ambient);
static void	print_lights(void *lights);

void	print_data(t_data *data)
{
	printf("\033[33m=============================================\033[0m\n\n");
	printf("\033[33mINFORMATION\033[0m\n\n");
	print_cam(&data->cam);
	print_ambient(data->ambient);
	ft_lstiter(data->lights, print_lights);
	printf("\n\033[32mK-D TREE STRUCTURE\033[0m\n");
	print_tree(data->tree);
	printf("\n\033[32mOBJECTS LIST\033[0m\n");
	ft_lstiter(data->objects, print_object_info_in_one_line);
	printf("\n\033[33mEND INFORMATION\033[0m\n\n");
	printf("\033[33m=============================================\033[0m\n\n");
}

static void	print_cam(t_cam *cam)
{
	printf("\033[32mCAMERA\033[0m\n"
		"position : \033[90m(%+5.2f, %+5.2f, %+5.2f)\033[0m\n"
		"direction : \033[90m(%+5.2f, %+5.2f, %+5.2f)\033[0m\n"
		"field of view(fov) : \033[90m%f (degrees)\033[0m\n\n",
		cam->position[0], cam->position[1], cam->position[2],
		cam->normal_unit[0], cam->normal_unit[1], cam->normal_unit[2],
		cam->fov);
}

static void	print_ambient(t_vector ambient)
{
	t_real		brightness;
	t_vector	normalized;
	int			cl[3];

	brightness = ambient[0];
	if (brightness < ambient[1])
		brightness = ambient[1];
	if (brightness < ambient[2])
		brightness = ambient[2];
	vec_product_scalar(normalized, ambient, 255 / brightness);
	cl[0] = (int)normalized[0];
	cl[1] = (int)normalized[1];
	cl[2] = (int)normalized[2];
	printf("\033[32mAMBIENT LIGHT\033[0m\nbrightness : %f\n"
		"RGB color : \033[38;2;%d;%d;%dm(%03d, %03d, %03d)\033[90m"
		"\033[0m\n\n", brightness, cl[0], cl[1], cl[2], cl[0], cl[1], cl[2]);
}

static void	print_lights(void *lights)
{
	t_light *const	ptr = (t_light *)lights;
	t_real			brightness;
	t_vector		normalized;
	int				cl[3];

	brightness = ptr->color[0];
	if (brightness < ptr->color[1])
		brightness = ptr->color[1];
	if (brightness < ptr->color[2])
		brightness = ptr->color[2];
	vec_product_scalar(normalized, ptr->color, 255 / brightness);
	cl[0] = (int)normalized[0];
	cl[1] = (int)normalized[1];
	cl[2] = (int)normalized[2];
	printf("\033[32mSPOT LIGHT\033[0m\n"
		"position : \033[90m(%+5.2f, %+5.2f, %+5.2f)\033[0m\n"
		"brightness : %f\n"
		"RGB color : \033[38;2;%d;%d;%dm(%03d, %03d, %03d)\033[90m"
		"\033[0m\n\n", ptr->position[0], ptr->position[1], ptr->position[2],
		brightness, cl[0], cl[1], cl[2], cl[0], cl[1], cl[2]);
}

void	print_manual(void)
{
	printf("\033[35mMove Camera Position : \033[0mW A S D E Q"
		" \033[90m(forward/backward/left/right/up/down)\n"
		"\033[35mRotate Camera Direction :"
		" \033[0mH J K L \033[90m(up/down/left/right)\n"
		"\033[35mZoom : \033[0mI O \033[90m(in/out)\n"
		"\033[35mExposure : \033[0mZ X \033[90m(decrease/increase)\n"
		"\033[35mHigh Resolution Rendering : \033[0mF\n"
		"\033[35mReset Settings : \033[0mR\n\n");
}
