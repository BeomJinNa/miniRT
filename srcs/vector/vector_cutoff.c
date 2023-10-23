/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cutoff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:29:41 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 19:33:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_cutoff_max(t_vector buffer, t_vector a, t_real max)
{
	buffer[0] = a[0];
	buffer[1] = a[1];
	buffer[2] = a[2];
	if (buffer[0] > max)
		buffer[0] = max;
	if (buffer[1] > max)
		buffer[1] = max;
	if (buffer[2] > max)
		buffer[2] = max;
}

void	vec_cutoff_min(t_vector buffer, t_vector a, t_real min)
{
	buffer[0] = a[0];
	buffer[1] = a[1];
	buffer[2] = a[2];
	if (buffer[0] < min)
		buffer[0] = min;
	if (buffer[1] < min)
		buffer[1] = min;
	if (buffer[2] < min)
		buffer[2] = min;
}
