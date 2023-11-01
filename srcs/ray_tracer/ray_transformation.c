/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:53:06 by bena              #+#    #+#             */
/*   Updated: 2023/11/02 04:07:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

void	get_converted_gyro_direction(t_vector buffer, t_vector v,
			t_real phi, t_vector convert)
{
	t_matrix	buffer1;
	t_matrix	buffer2;
	t_matrix	buffer3;

	set_rotation_matrix_theta(buffer1, sinf(convert[0]), cosf(convert[0]));
	set_rotation_matrix_phi(buffer2,
		sinf(phi + convert[1] - M_PI_2), cosf(phi + convert[1] - M_PI_2));
	mat_product(buffer3, buffer2, buffer1);
	buffer[0] = vec_dot_product(buffer3[0], v);
	buffer[1] = vec_dot_product(buffer3[1], v);
	buffer[2] = vec_dot_product(buffer3[2], v);
}
