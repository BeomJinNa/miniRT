/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:40:22 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:23:35 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_utils.h"
#include "../utils/utils.h"
#include "../parse_utils/parse_utils.h"
#include "../parse.h"
#include "vector.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_words_to_cylinder(char **words, t_object *cylinder);

/*
cy position       normal       diameter  height  rgb
cy 50.0,0.0,20.6  0.0,0.0,1.0  14.2      21.42   10,0,255
*/
t_object	*convert_line_to_cylinder(char *line)
{
	t_object*const	new_obj = malloc(sizeof(t_object));
	char**const		words = ft_split(line, ' ');
	size_t			word_len;

	word_len = ptr_len((void **)words);
	if (word_len < 6
		|| parse_words_to_cylinder(words, new_obj)
		|| parse_additional(words, 6, new_obj))
	{
		parse_error("failed to parse cylinder : ", line);
		parse_error("\tL valid form : ",
			"cy <center position vector> <axis vector (normal)>\
<diameter> <height> <rgb>");
		free(new_obj);
		recursive_free(words, 2);
		return (NULL);
	}
	recursive_free(words, 2);
	return (new_obj);
}

static int	parse_words_to_cylinder(char **words, t_object *cylinder)
{
	t_vector	pos_norm[2];
	t_real		diameter;
	t_real		height;
	t_vector	rgb;
	int			result;

	if (parse_vector(words[1], pos_norm[0])
		|| parse_normalized_vector(words[2], pos_norm[1])
		|| parse_unsigned_number(words[3], &diameter)
		|| parse_unsigned_number(words[4], &height)
		|| parse_rgb(words[5], rgb))
	{
		parse_error("failed to parse cylinder", "");
		return (1);
	}
	vec_product_scalar(pos_norm[1], pos_norm[1], height);
	result = init_cylinder(cylinder, pos_norm[0], pos_norm[1],
			diameter / (t_real)2.0);
	if (!result)
		vec_copy(cylinder->texture.reflectance, rgb_to_ratio(rgb, rgb, 1.0));
	return (result);
}
