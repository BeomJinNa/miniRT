/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:04:30 by bena              #+#    #+#             */
/*   Updated: 2023/10/26 06:25:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "object.h"
# include "s_ray.h"
# include "stat.h"

# define M_SURFACE_OFFSET_SIZE 0.01f

typedef struct s_raygap
{
	t_real	cosine;
	t_real	sine;
	t_real	distance_sq;
}	t_raygap;

typedef struct s_intersection_buffer
{
	t_vector	position;
	t_vector	normal_unit;
	t_real		dist;
}	t_hit_buffer;

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

void			shoot_a_ray(t_vector buffer, t_ray ray,
					t_data *data, int depth);
t_ray			set_ray(t_vector position, t_vector normal_unit, t_real weight);
t_intersection	get_intersection(t_ray *ray, t_object *object);
t_intersection	return_void_intersection(void);
t_intersection	get_closest_intersection(t_ray *ray, t_data *data);
int				is_point_in_plane(t_vector point_position,
					t_vector plane_position, t_vector plane_normal);
void			get_reflected_ray(t_vector buffer, t_vector ray_normal_unit,
					t_vector surface_normal_unit);
t_real			get_nearest_point_with_ray(t_ray *ray,
					t_vector position, t_vector normal_unit);
void			compute_scattering_lights(t_vector buffer,
					t_intersection *hitpoint, t_data *data, int depth);
void			compute_lighting_from_spotlights(t_vector buffer,
					t_intersection *hitpoint, t_data *data);
#endif
