/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:08 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 03:52:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_ray.h"

t_ray	set_ray(t_vector position, t_vector normal_unit, t_real weight)
{
	t_ray	output;

	vec_copy(output.position, position);
	vec_copy(output.normal_unit, normal_unit);
	output.weight = weight;
	return (output);
}
