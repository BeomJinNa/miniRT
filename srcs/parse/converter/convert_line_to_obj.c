/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:32:06 by dowon             #+#    #+#             */
/*   Updated: 2023/10/23 20:04:16 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "convert_utils.h"
#include "stat.h"
#include <stdlib.h>

int	convert_line_to_obj(void *pline, void *pdata)
{
	char*const		line = pline;
	t_data*const	data = pdata;
	t_object		*result_obj;

	result_obj = NULL;
	if (ft_strncmp(line, "A ", 2) == 0)
		return (convert_line_to_ambient(line, data));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (convert_line_to_camera(line, data));
	else if (ft_strncmp(line, "L ", 2) == 0)
		return (convert_line_to_light(line, data));
	else if (ft_strncmp(line, "sp ", 3) == 0)
		result_obj = convert_line_to_sphere(line);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		result_obj = convert_line_to_plane(line);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		result_obj = convert_line_to_cylinder(line);
	else
		return (1);
	if (result_obj == NULL)
		return (1);
	ft_lstadd_back(&data->objects, ft_lstnew(result_obj));
	return (0);
}