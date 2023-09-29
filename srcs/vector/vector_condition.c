/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 13:52:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "stat.h"
#include <stddef.h>

int	is_vector_zero(t_vector vec)
{
	if (vec == NULL)
		return (-1);
	if (-M_VECTOR_MIN_SCALE < vec[0] && vec[0] < M_VECTOR_MIN_SCALE
	&& -M_VECTOR_MIN_SCALE < vec[1] && vec[1] < M_VECTOR_MIN_SCALE
	&& -M_VECTOR_MIN_SCALE < vec[2] && vec[2] < M_VECTOR_MIN_SCALE)
		return (1);
	return (0);
}
