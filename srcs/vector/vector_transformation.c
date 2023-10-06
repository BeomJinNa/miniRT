/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:10:24 by bena              #+#    #+#             */
/*   Updated: 2023/10/06 11:31:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_real	vec_size(const t_vector vec)
{
	const t_real	square = vec_dot_product(vec, vec);

	if (square <= 0)
		return (0);
	return (sqrtf(square));
}

void	*vec_norm(t_vector buffer, t_vector vec)
{
	const t_real	length = vec_size(vec);

	buffer[0] = vec[0] / length;
	buffer[1] = vec[1] / length;
	buffer[2] = vec[2] / length;
	return (buffer);
}

t_real	vec_cosine_similarity(const t_vector a, const t_vector b)
{
	return (vec_dot_product(a, b) / (vec_size(a) * vec_size(b)));
}

void	*vec_min(t_vector buffer, t_vector a, t_vector b)
{
	t_vector	temp;

	temp[0] = a[0];
	temp[1] = a[1];
	temp[2] = a[2];
	if (a[0] > b[0])
		temp[0] = b[0];
	if (a[1] > b[1])
		temp[1] = b[1];
	if (a[2] > b[2])
		temp[2] = b[2];
	buffer[0] = temp[0];
	buffer[1] = temp[1];
	buffer[2] = temp[2];
	return (buffer);
}

void	*vec_max(t_vector buffer, t_vector a, t_vector b)
{
	t_vector	temp;

	temp[0] = a[0];
	temp[1] = a[1];
	temp[2] = a[2];
	if (a[0] < b[0])
		temp[0] = b[0];
	if (a[1] < b[1])
		temp[1] = b[1];
	if (a[2] < b[2])
		temp[2] = b[2];
	buffer[0] = temp[0];
	buffer[1] = temp[1];
	buffer[2] = temp[2];
	return (buffer);
}
