/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounding_volume.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:07:25 by bena              #+#    #+#             */
/*   Updated: 2023/09/25 22:26:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"

void	set_bv_on_plane(t_object *plane)
{
	vector	unit;
	t_real	cos_direction;
	t_real	sin_direction;
	int		axis;

	axis = 0;
	while (axis < 3)
	{
		unit[0] = 0;
		unit[1] = 0;
		unit[2] = 0;
		unit[axis] = 1.0;
		cos_direction = vec_cosine_similarity(plane->u_data.plane.normal, unit);
		sin_direction = sqrt(1 - cos_direction * cos_direction);
		plane->bv.max[axis] = plane->u_data.plane.position[axis]
			+ sin_direction * plane->u_data.plane.radius;
		plane->bv.min[axis] = plane->u_data.plane.position[axis]
			- sin_direction * plane->u_data.plane.radius;
		axis++;
	}
}
