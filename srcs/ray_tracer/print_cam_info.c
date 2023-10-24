/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cam_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:47:14 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 06:08:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include <math.h>
#include <stdio.h>

void	print_cam_info(t_stat *stat)
{
	t_cam *const	cam = &stat->data.cam;
	t_real			focal_length;

	focal_length = 43.27 / (2 * tanf(cam->fov * M_PI_2 / 180));
	printf("\033[33mCAM STATUS\n\n"
		"\033[32mPosition  \033[37m(%+5.2f, %+5.2f, %+5.2f)\n"
		"\033[32mDirection \033[37m(%+5.2f, %+5.2f, %+5.2f)\n",
		cam->position[0], cam->position[1], cam->position[2],
		cam->normal_unit[0], cam->normal_unit[1], cam->normal_unit[2]);
	if (focal_length > 0)
		printf("\033[32mFOV       \033[37m%.1f \033[36mDegrees"
			"\033[90m (%.1f mm)\n\033[0m",
			cam->fov, focal_length);
	else
		printf("\033[32mFOV       \033[37m%.1f \033[36mDegrees"
			"\033[90m (--- mm)\n\033[0m",
			cam->fov);
}

void	delete_cam_info(void)
{
	int	i;

	printf("\r\033[7Am");
	i = 0;
	while (i < 7)
	{
		printf("\033[Km\r \n");
		i++;
	}
	printf("\033[7Am \r");
}
