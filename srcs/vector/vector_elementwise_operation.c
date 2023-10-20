/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elementwise_operation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/10/20 23:35:24 by bena             ###   ########.fr       */
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
