/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:08 by bena              #+#    #+#             */
/*   Updated: 2023/10/20 18:50:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_ray.h"
#include "stat.h"

void	*shoot_a_ray(t_vector buffer, t_ray ray, t_data *data);

t_ray	set_ray(t_vector position, t_vector normal_unit, t_real weight)
{
	t_ray	output;

	vec_copy(output.position, position);
	vec_copy(output.normal_unit, normal_unit);
	output.weight = weight;
	return (output);
}
