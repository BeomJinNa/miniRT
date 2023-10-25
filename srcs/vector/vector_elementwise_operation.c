/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elementwise_operation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 04:08:08 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vec_product_element_wise(t_vector buffer, t_vector a, t_vector b)
{
	buffer[0] = a[0] * b[0];
	buffer[1] = a[1] * b[1];
	buffer[2] = a[2] * b[2];
	return (buffer);
}

void	*vec_divide_element_wise(t_vector buffer, t_vector a, t_vector b)
{
	buffer[0] = a[0] / b[0];
	buffer[1] = a[1] / b[1];
	buffer[2] = a[2] / b[2];
	return (buffer);
}

void	*vec_abs(t_vector buffer, t_vector source)
{
	buffer[0] = source[0];
	buffer[1] = source[1];
	buffer[2] = source[2];
	if (buffer[0] < 0)
		buffer[0] = -buffer[0];
	if (buffer[1] < 0)
		buffer[1] = -buffer[1];
	if (buffer[2] < 0)
		buffer[2] = -buffer[2];
	return (buffer);
}
