/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_plane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:36:56 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:24:06 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"
#include "../utils/utils.h"
#include "../parse_utils/parse_utils.h"
#include "convert_utils.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_words_to_plane(char **words, t_object *plane);

/*
pl position      normalized  rgb
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225 [radius]
*/
t_object	*convert_line_to_plane(char *line)
{
	t_object*const	new_obj = malloc(sizeof(t_object));
	char**const		words = ft_split(line, ' ');

	if (new_obj == NULL || words == NULL)
	{
		if (new_obj != NULL)
			free(new_obj);
		if (words != NULL)
			recursive_free(words, 2);
		return (NULL);
	}
	if (ptr_len((void **)words) < 4
		|| parse_words_to_plane(words, new_obj)
		|| parse_additional(words, 4, new_obj))
	{
		parse_error("failed to parse plane : ", line);
		parse_error("\tL valid form : ",
			"pl <position vector> <direction vector (normal)> <rgb>");
		free(new_obj);
		recursive_free(words, 2);
		return (NULL);
	}
	recursive_free(words, 2);
	return (new_obj);
}

static int	parse_words_to_plane(char **words, t_object *plane)
{
	t_vector		position;
	t_vector		normal;
	t_vector		rgb;
	int				result;

	if (parse_vector(words[1], position)
		|| parse_normalized_vector(words[2], normal)
		|| parse_rgb(words[3], rgb))
		return (1);
	result = init_plane(plane, position, normal, 0.0);
	if (!result)
		vec_copy(plane->texture.reflectance, rgb_to_ratio(rgb, rgb, 1.0));
	return (result);
}
