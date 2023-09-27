/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/09/27 13:34:38 by bena             ###   ########.fr       */
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
	buffer[0] = a[0] / b;
	buffer[1] = a[1] / b;
	buffer[2] = a[2] / b;
	return (buffer);
}
