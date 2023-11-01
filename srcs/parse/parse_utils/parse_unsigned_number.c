/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:19:54 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"
#include "../parse.h"

int	parse_unsigned_number(char *line, t_real *real)
{
	if (*line == '-')
	{
		parse_error("failed to validate unsigned number : ", line);
		parse_error("\tL string starts with -", "");
		return (1);
	}
	if (parse_real_number(line, real))
	{
		parse_error("\tL failed to parse unsigned number : ", line);
		return (1);
	}
	if (*real <= 0.0)
	{
		parse_error("failed to validate unsigned number : ", line);
		parse_error("\tL parsed result is negative.", "(or it is too big.)");
		return (1);
	}
	return (0);
}
