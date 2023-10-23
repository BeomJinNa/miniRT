/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_degree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:40:24 by dowon             #+#    #+#             */
/*   Updated: 2023/10/18 18:55:50 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

static int	validate_degree(t_real real);

int	parse_degree(const char *line, t_real *real)
{
	int	result;
	
	result = parse_real_number(line, real);
	if (result || !validate_degree(*real))
		result = 1;
	return (result);
}

static int	validate_degree(t_real real)
{
	if (real < 0.0 || 180.0 < real)
		return (0);
	return (1);
}