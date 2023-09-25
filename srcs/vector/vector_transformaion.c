/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transformaion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:10:24 by bena              #+#    #+#             */
/*   Updated: 2023/09/25 21:33:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_real	vec_size(vector vec)
{
	return (sqrt(vec_dot_product(vec, vec)));
}

void	*vec_norm(vector buffer, vector vec)
{
	const t_real	length = vec_size(vec);

	buffer[0] = vec[0] / length;
	buffer[1] = vec[1] / length;
	buffer[2] = vec[2] / length;
	return (buffer);
}

t_real	vec_cosine_similarity(vector a, vector b)
{
	return (vec_dot_product(a, b) / (vec_size(a) * vec_size(b)));
}
