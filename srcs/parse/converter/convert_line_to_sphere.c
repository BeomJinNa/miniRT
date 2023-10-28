/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:39:58 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 13:43:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_utils/parse_utils.h"
#include "../utils/utils.h"
#include "convert_utils.h"
#include "stat.h"

static int	parse_words_to_sphere(char **words, t_object *obj);

/*
sp position       radius  rgb
sp 0.0,0.0,20.6   12.6    10,0,255
*/
t_object	*convert_line_to_sphere(char *line)
{
	t_object*const	new_obj = malloc(sizeof(t_object));
	char**const		words = ft_split(line, ' ');

	if (ptr_len((void **)words) != 4
		|| parse_words_to_sphere((char **)words, new_obj))
	{
		free(new_obj);
		recursive_free(words, 2);
		return (NULL);
	}
	return (new_obj);
}

static int	parse_words_to_sphere(char **words, t_object *obj)
{
	t_vector		position;
	t_real			diameter;
	t_vector		rgb;
	int				result;

	if (parse_vector(words[1], position)
		|| parse_degree(words[2], &diameter)
		|| parse_rgb(words[3], rgb))
		return (1);
	result = init_sphere(obj, position, diameter / 2.0f);
	if (!result)
		vec_copy(obj->texture.reflectance, rgb_to_ratio(rgb, rgb, 1.0));
	return (result);
}
