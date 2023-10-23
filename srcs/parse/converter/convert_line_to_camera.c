/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:14:58 by dowon             #+#    #+#             */
/*   Updated: 2023/10/23 16:13:47 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include "../parse_utils/parse_utils.h"
#include "../utils/utils.h"
#include <stdlib.h>

static int	parse_words_to_camera(char**const words, t_cam *cam);

/*
C position   normal fov(horizontal)
C -50.0,0,20 0,0,1  70
*/
int	convert_line_to_camera(char *line, t_data *data)
{
	char**const	words = ft_split(line, ' ');
	int			is_failed;

	if (words == NULL)
		return (1);
	is_failed = (ptr_len((void **)words) != 3
			|| parse_words_to_camera(words, &data->cam));
	recursive_free(words, 2);
	return (is_failed);
}

static int	parse_words_to_camera(char**const words, t_cam *cam)
{
	t_vector	position;
	t_vector	normal;
	t_real		hfov;

	if (parse_vector(words[1], position)
		|| parse_normalized_vector(words[2], normal)
		|| parse_degree(words[3], &hfov))
		return (1);
	vec_copy(cam->position, position);
	vec_copy(cam->normal_unit, normal);
	cam->fov = hfov;
	return (0);
}
