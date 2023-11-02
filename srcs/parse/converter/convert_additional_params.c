/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_additional_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:13:42 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:03:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_utils.h"
#include "../utils/utils.h"
#include "../parse_utils/parse_utils.h"
#include "../parse.h"
#include "libft.h"

static int	validate_checker(char *word)
{
	if (ft_strncmp(word, "chk", 4))
	{
		parse_error("checker option should be 'chk' not : ", word);
		return (0);
	}
	return (1);
}
static int	parse_additional_single(char **words, size_t base_form_len,
				t_object *obj);

int	parse_additional(char **words, size_t base_form_len, t_object *obj)
{
	const size_t	word_len = ptr_len((void **)words);

	if (base_form_len == word_len)
		return (0);
	if (word_len == base_form_len + 1)
		return (parse_additional_single(words, base_form_len, obj));
	else if (word_len == base_form_len + 2)
	{
		if (!validate_checker(words[base_form_len]))
			return (1);
		else if (parse_ratio(words[base_form_len + 1],
				&obj->texture.reflection_ratio))
			return (1);
		obj->texture.flags = FLAG_TEXTURE_CHECKER;
	}
	else
	{
		parse_error("Too many options. valid form : ", "<chk> <reflectance>");
		return (1);
	}
	return (0);
}

static int	parse_additional_single(char **words, size_t base_form_len,
	t_object *obj)
{
	if (ft_isdigit(words[base_form_len][0]) || words[base_form_len][0] == '-')
	{
		if (parse_ratio(words[base_form_len],
				&obj->texture.reflection_ratio))
			return (1);
		return (0);
	}
	if (!validate_checker(words[base_form_len]))
		return (1);
	obj->texture.flags = FLAG_TEXTURE_CHECKER;
	return (0);
}
