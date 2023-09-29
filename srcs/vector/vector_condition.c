/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 21:30:40 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "stat.h"
#include <stddef.h>

int	is_vector_zero(const t_vector vec)
{
	if (vec == NULL)
		return (-1);
	if ((-M_VECTOR_MIN_SCALE) < vec[0] && vec[0] < M_VECTOR_MIN_SCALE
		&& (-M_VECTOR_MIN_SCALE) < vec[1] && vec[1] < M_VECTOR_MIN_SCALE
		&& (-M_VECTOR_MIN_SCALE) < vec[2] && vec[2] < M_VECTOR_MIN_SCALE)
		return (1);
	return (0);
}

int	are_values_same(t_real value1, t_real value2)
{
	const t_real	diff = value1 - value2;

	if ((-M_VECTOR_MIN_SCALE) < diff && diff < M_VECTOR_MIN_SCALE)
		return (1);
	return (0);
}
