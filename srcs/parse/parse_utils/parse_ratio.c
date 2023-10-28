/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:37:48 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 18:37:05 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"
#include "../parse.h"

static int	validate_ratio(t_real real);

int	parse_ratio(const char *line, t_real *real)
{
	if (parse_real_number(line, real))
		return (1);
	if (!validate_ratio(*real))
	{
		print_to_stderr("failed to validate ratio : ", line);
		return (1);
	}
	return (0);
}

static int	validate_ratio(t_real real)
{
	if (real < 0.0 || 1.0 < real)
		return (0);
	return (1);
}
