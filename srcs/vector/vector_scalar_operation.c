/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 01:02:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "vector.h"

void	*vec_add_scalar(t_vector buffer, t_vector a, t_real b)
{
	buffer[0] = a[0] + b;
	buffer[1] = a[1] + b;
	buffer[2] = a[2] + b;
	return (buffer);
}

void	*vec_subtract_scalar(t_vector buffer, t_vector a, t_real b)
{
	buffer[0] = a[0] - b;
	buffer[1] = a[1] - b;
	buffer[2] = a[2] - b;
	return (buffer);
}

void	*vec_product_scalar(t_vector buffer, t_vector a, t_real b)
{
	buffer[0] = a[0] * b;
	buffer[1] = a[1] * b;
	buffer[2] = a[2] * b;
	return (buffer);
}

void	*vec_divide_scalar(t_vector buffer, t_vector a, t_real b)
{
	const t_real	inverse = 1 / b;

	buffer[0] = a[0] * inverse;
	buffer[1] = a[1] * inverse;
	buffer[2] = a[2] * inverse;
	return (buffer);
}

void	*vec_invert(t_vector buffer, t_vector source)
{
	buffer[0] = -source[0];
	buffer[1] = -source[1];
	buffer[2] = -source[2];
	return (buffer);
}
