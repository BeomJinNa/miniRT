/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/09/13 02:59:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "type.h"
#include "vector.h"

void	vec_add(vector buffer, vector a, vector b)
{
	buffer[0] = a[0] + b[0];
	buffer[1] = a[1] + b[1];
	buffer[2] = a[2] + b[2];
}

void	vec_subtract(vector buffer, vector a, vector b)
{
	buffer[0] = a[0] - b[0];
	buffer[1] = a[1] - b[1];
	buffer[2] = a[2] - b[2];
}

t_real	vec_dot_product(vector a, vector b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

void	vec_cross_product(vector buffer, vector a, vector b)
{
	buffer[0] = a[1] * b[2] - a[2] * b[1];
	buffer[1] = a[2] * b[0] - a[0] * b[2];
	buffer[2] = a[0] * b[1] - a[1] * b[0];
}

void	vec_norm(vector buffer, vector vec)
{
	const t_real	length = sqrt(vec_dot_product(vec, vec));

	buffer[0] = vec[0] / length;
	buffer[1] = vec[1] / length;
	buffer[2] = vec[2] / length;
}
