/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_a_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:51:28 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 21:20:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"

static t_intersection	get_intersection(t_ray *ray, t_data *data);
static int	find_closest_hit_point(t_object **target,
				t_real *distance, t_data *data);

void	*shoot_a_ray(t_vector buffer, t_ray ray, t_stat *stat)
{
	t_intersection	hitpoint;

	//hitpoint = get_intersection(&ray, stat->data);
	if (hitpoint.hit_object == M_HIT_NONE)
		return (vec_set_zero(buffer));
	//buffer = get_value_from_hitpoint(hitpoint);
	vec_product_scalar(buffer, buffer, ray.weight);
	return (buffer);
}

static t_intersection	get_intersection(t_ray *ray, t_data *data)
{
	t_intersection	output;
	t_object		*hit_object;
	t_real			distance;

	ft_memset(&output, 0, sizeof(output));
	if (find_closest_hit_point(&hit_object, &distance, data))
		return (output);
	return (output);
}

static int	find_closest_hit_point(t_object **target,
				t_real *distance, t_data *data)
{
	return (0);
}
