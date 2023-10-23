/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:37:48 by dowon             #+#    #+#             */
/*   Updated: 2023/10/18 18:55:59 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

static int	validate_ratio(t_real real);

int	parse_ratio(const char *line, t_real *real)
{
	int	result;

	result = parse_real_number(line, real);
	if (result || !validate_ratio(*real))
		result = 1;
	return (result);
}

static int	validate_ratio(t_real real)
{
	if (real < 0.0 || 1.0 < real)
		return (0);
	return (1);
}