/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ray.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:46:37 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 01:21:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_RAY_H
# define S_RAY_H

# include "vector.h"

typedef struct s_ray
{
	t_vector	position;
	t_vector	normal_unit;
	t_real		weight;
}	t_ray;
#endif
