/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:02:27 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 03:25:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

void	get_new_unit_vector_by_polar(t_vector buffer, t_real theta, t_real phi)
{
	buffer[0] = cosf(theta) * sinf(phi);
	buffer[1] = sinf(theta) * sinf(phi);
	buffer[2] = cosf(phi);
	if (phi < 0)
	{
		buffer[0] = -buffer[0];
		buffer[1] = -buffer[1];
	}
}
