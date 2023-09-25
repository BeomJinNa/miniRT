/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/09/25 20:38:34 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "vector.h"

void	*vec_copy(vector destination, vector source)
{
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
	return (destination);
}

void	*vec_add(vector buffer, vector a, vector b)
{
	buffer[0] = a[0] + b[0];
	buffer[1] = a[1] + b[1];
	buffer[2] = a[2] + b[2];
	return (buffer);
}

void	*vec_subtract(vector buffer, vector a, vector b)
{
	buffer[0] = a[0] - b[0];
	buffer[1] = a[1] - b[1];
	buffer[2] = a[2] - b[2];
	return (buffer);
}

t_real	vec_dot_product(vector a, vector b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

void	*vec_cross_product(vector buffer, vector a, vector b)
{
	buffer[0] = a[1] * b[2] - a[2] * b[1];
	buffer[1] = a[2] * b[0] - a[0] * b[2];
	buffer[2] = a[0] * b[1] - a[1] * b[0];
	return (buffer);
}
