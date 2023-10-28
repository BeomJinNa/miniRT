/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_degree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:40:24 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 18:47:19 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"
#include "parse_utils.h"

static int	validate_degree(t_real real);

int	parse_degree(const char *line, t_real *real)
{
	if (parse_real_number(line, real))
		return (1);
	if (!validate_degree(*real))
	{
		print_to_stderr("failed to validate degree : ", line);
		return (1);
	}
	return (0);
}

static int	validate_degree(t_real real)
{
	if (real < 0.0 || 180.0 < real)
		return (0);
	return (1);
}
