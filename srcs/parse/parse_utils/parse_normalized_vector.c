/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalized_vector.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:53 by dowon             #+#    #+#             */
/*   Updated: 2023/10/25 06:41:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

static int	validate_normalized_vector(t_vector vec);

int	parse_normalized_vector(const char *line, t_vector vec)
{
	int	result;

	result = parse_vector(line, vec);
	if (result || !validate_normalized_vector(vec))
		result = 1;
	return (result);
}

#include <stdio.h>
static int	validate_normalized_vector(t_vector vec)
{
//	printf("%f,%f,%f normal : %f\n", vec[0], vec[1], vec[2], vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	if (are_values_same(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2], (t_real)1.0) == 0)
		return (0);
	return (1);
}
