/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:53:06 by bena              #+#    #+#             */
/*   Updated: 2023/11/01 20:51:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

t_real	get_converted_gyro_theta(t_real dtheta, t_real dphi)
{
	return (atan2f(sinf(dtheta), cosf(dphi) * cosf(dtheta)));
}

t_real	get_converted_gyro_phi(t_real dtheta, t_real dphi)
{
	return (asinf(-cosf(dtheta) * sinf(dphi)));
}
