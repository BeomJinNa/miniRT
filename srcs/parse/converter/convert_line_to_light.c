/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:39:27 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_utils.h"
#include "libft.h"
#include "vector.h"
#include "stat.h"
#include "../parse.h"
#include "../parse_utils/parse_utils.h"
#include "../utils/utils.h"
#include <stdlib.h>

static int	parse_words_to_light(char **words, t_light *light);

/*
L position        brightness  color
L -40.0,50.0,0.0  0.6         10,0,255
*/
int	convert_line_to_light(char *line, t_data *data)
{
	t_light*const	light = malloc(sizeof(t_light));
	char**const		words = ft_split(line, ' ');
	int				is_failed;

	if (light == NULL || words == NULL)
	{
		if (light != NULL)
			free(light);
		if (words != NULL)
			recursive_free(words, 2);
		return (1);
	}
	is_failed = (ptr_len((void **)words) != 4
			|| parse_words_to_light(words, light));
	recursive_free(words, 2);
	if (is_failed)
	{
		parse_error("failed to parse light : ", line);
		free(light);
	}
	else
		ft_lstadd_back(&data->lights, ft_lstnew(light));
	return (is_failed);
}

static int	parse_words_to_light(char **words, t_light *light)
{
	t_vector		position;
	t_vector		rgb;
	t_real			brightness;

	if (parse_vector(words[1], position)
		|| parse_ratio(words[2], &brightness)
		|| parse_rgb(words[3], rgb))
		return (1);
	vec_copy(light->position, position);
	vec_copy(light->color, rgb_to_ratio(rgb, rgb, brightness));
	return (0);
}
