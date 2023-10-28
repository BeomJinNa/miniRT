/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_additional_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:13:42 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 16:43:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "convert_utils.h"
#include "../utils/utils.h"
#include "../parse_utils/parse_utils.h"
#include "vector.h"
#include "libft.h"
#include <stdlib.h>

int	parse_additional(char **words, size_t base_form_len, t_object *obj)
{
	const size_t	word_len = ptr_len((void **)words);

	if (base_form_len == word_len)
		return (0);
	if (word_len == base_form_len + 1)
	{
		if (ft_strncmp(words[base_form_len], "chk", 3) == 0)
			obj->texture.flags = FLAG_TEXTURE_CHECKER;
		else if (parse_ratio(words[base_form_len],
				&obj->texture.reflection_ratio))
			return (1);
		else
			return (1);
	}
	else if (word_len == base_form_len + 2)
	{
		if (ft_strncmp(words[base_form_len], "chk", 3) != 0
			|| (parse_ratio(words[base_form_len + 1],
					&obj->texture.reflection_ratio)))
			return (1);
		obj->texture.flags = FLAG_TEXTURE_CHECKER;
	}
	else
		return (1);
	return (0);
}
