/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:54:47 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"
#include "libft.h"
#include "../utils/utils.h"
#include "../parse.h"
#include <stdlib.h>

static int	is_valid_vector_form(const char *str)
{
	const char	*iter;
	int			comma_cnt;

	iter = str;
	comma_cnt = 0;
	while (*iter != '\0')
	{
		if (*iter == ',')
			++comma_cnt;
		++iter;
	}
	if (comma_cnt != 2)
		return (0);
	return (1);
}

int	parse_vector(const char *str, t_vector v)
{
	char**const		word = ft_split(str, ',');
	int				is_failed;

	is_failed = 0;
	if (ptr_len((void **)word) != 3 || !is_valid_vector_form(str))
	{
		parse_error("Not a valid form of vector : ", str);
		is_failed = 1;
	}
	if (is_failed || parse_real_number(word[0], &v[0])
		|| parse_real_number(word[1], &v[1])
		|| parse_real_number(word[2], &v[2]))
	{
		parse_error("Failed to parse each number of vector \
in word : ", str);
		is_failed = 1;
	}
	recursive_free(word, 2);
	return (is_failed);
}
