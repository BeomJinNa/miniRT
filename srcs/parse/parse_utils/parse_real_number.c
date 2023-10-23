/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_real_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:54:18 by dowon             #+#    #+#             */
/*   Updated: 2023/10/23 18:07:04 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"
#include "libft.h"
#include <stdlib.h>

static void	get_real_part(const char *str, t_real *real)
{
	*real = (t_real)0.0;
	while (*str != '\0')
	{
		*real = *real * (t_real)10.0 + (t_real)(*str - '0');
		++str;
	}
}

static void	get_imaginary_part(const char *str, t_real *imaginary)
{
	const size_t	len = ft_strlen(str);
	size_t			idx;

	*imaginary = (t_real)0.0;
	idx = 0;
	while (idx < len)
	{
		*imaginary = *imaginary / (t_real)10.0
			+ (t_real)(str[len - 1 - idx] - '0') / (t_real)10.0;
		++idx;
	}
}

static int	is_valid_real_number_form(const char *str)
{
	const char*const	origin = str;
	int					is_dot_included;

	is_dot_included = 0;
	if (*str == '-')
		++str;
	if (*str == '\0' || *str == '.')
		return (0);
	while (*str != '\0')
	{
		if (*str == '.')
		{
			if (is_dot_included == 1)
				return (0);
			if (!ft_isdigit(*(str + 1)))
				return (0);
			if (str == origin)
				return (0);
			is_dot_included = 1;
		}
		else if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}
#include <stdio.h>
int	parse_real_number(const char *str, t_real *real)
{
	char**const	word = ft_split(str, '.');
	t_real		real_part;
	t_real		imaginary_part;

	if (!is_valid_real_number_form(str))
		return (1);
	get_real_part(word[0] + (word[0][0] == '-'), &real_part);
	if (word[1] != NULL)
		get_imaginary_part(word[1], &imaginary_part);
	else
		imaginary_part = 0.0;
	*real = real_part + imaginary_part;
	if (word[0][0] == '-')
		*real = -*real;
	return (0);
}
