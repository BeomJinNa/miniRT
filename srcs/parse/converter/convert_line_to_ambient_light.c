/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_ambient_light.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:18:54 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:23:24 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_utils.h"
#include "../parse.h"
#include "../utils/utils.h"
#include "../parse_utils/parse_utils.h"
#include "vector.h"
#include "stat.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_words_to_ambient(const char **words, t_real *ambient);

/*
A ratio  rgb
A 0.2    255,255,255
*/
int	convert_line_to_ambient(char *line, t_data *data)
{
	const char		**words = (const char **)ft_split(line, ' ');

	if (words == NULL)
		return (0);
	if (ptr_len((void **)words) != 3
		|| parse_words_to_ambient(words, data->ambient))
	{
		parse_error("failed to parse ambient light : ", line);
		parse_error("\tL valid form : ", "A <ratio> <rgb>");
		recursive_free(words, 2);
		return (1);
	}
	recursive_free(words, 2);
	return (0);
}

static int	parse_words_to_ambient(const char **words, t_real *ambient)
{
	t_real			ratio;
	t_vector		rgb;

	if (parse_ratio(words[1], &ratio) || parse_rgb(words[2], rgb))
		return (1);
	vec_copy(ambient, rgb_to_ratio(rgb, rgb, ratio));
	return (0);
}
