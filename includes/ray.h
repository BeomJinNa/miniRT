/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:04:30 by bena              #+#    #+#             */
/*   Updated: 2023/09/30 21:22:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "s_ray.h"
# include "stat.h"

typedef struct s_intersection
{
	t_vector	position;
	t_vector	reflectance;
	t_vector	transmittance;
	t_vector	normal_unit;
	t_vector	reflection_direction_unit;
	t_real		reflection_ratio;
	t_real		distance;
	t_ray		*ray;
	t_object	*object;
}	t_intersection;

void			*shoot_a_ray(t_vector buffer, t_ray ray, t_data *data);
t_intersection	get_intersection(t_ray *ray, t_object *object);
#endif
