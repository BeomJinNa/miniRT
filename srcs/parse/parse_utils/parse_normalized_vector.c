/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalized_vector.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:53 by dowon             #+#    #+#             */
/*   Updated: 2023/10/25 20:40:00 by dowon            ###   ########.fr       */
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
	vec_norm(vec, vec);
	return (result);
}

static int	validate_normalized_vector(t_vector vec)
{
	const t_real	size = vec_size(vec);

	if (vec[0] < -1.0 || 1.0 < vec[0]
		|| vec[1] < -1.0 || 1.0 < vec[1]
		|| vec[2] < -1.0 || 1.0 < vec[2])
		return (0);
	if (size < 0.9 || 1.1 < size)
		return (0);
	return (1);
}
