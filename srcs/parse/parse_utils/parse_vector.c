/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:54:47 by dowon             #+#    #+#             */
/*   Updated: 2023/10/18 18:43:07 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"
#include "libft.h"
#include "../utils/utils.h"
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
	int				result;

	if (ptr_len((void **)word) != 3 || !is_valid_vector_form(str))
		result = 1;
	else
		result = 0;
	if (result || parse_real_number(word[0], &v[0])
		|| parse_real_number(word[1], &v[1])
		|| parse_real_number(word[2], &v[2]))
		result = 1;
	recursive_free(word, 2);
	return (result);
}
