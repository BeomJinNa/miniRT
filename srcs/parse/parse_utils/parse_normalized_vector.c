/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalized_vector.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:53 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:00:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"
#include "parse_utils.h"

static int	validate_normalized_vector(t_vector vec);

int	parse_normalized_vector(const char *line, t_vector vec)
{
	if (parse_vector(line, vec))
		return (1);
	if (!validate_normalized_vector(vec))
	{
		print_to_stderr("failed to validate normalized vector : ", line);
		return (1);
	}
	vec_norm(vec, vec);
	return (0);
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
