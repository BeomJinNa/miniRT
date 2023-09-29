/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:47:36 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 21:30:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "type.h"

typedef t_real	t_vector[3];

enum	e_axis_type
{
	M_AXIS_X = 0,
	M_AXIS_Y = 1,
	M_AXIS_Z = 2,
};

void	*vec_copy(t_vector destination, const t_vector source);
void	*vec_add(t_vector buffer, t_vector a, t_vector b);
void	*vec_add_scalar(t_vector buffer, t_vector a, t_real b);
void	*vec_subtract(t_vector buffer, t_vector a, t_vector b);
void	*vec_subtract_scalar(t_vector buffer, t_vector a, t_real b);
t_real	vec_dot_product(const t_vector a, const t_vector b);
void	*vec_cross_product(t_vector buffer, t_vector a, t_vector b);
void	*vec_product_scalar(t_vector buffer, t_vector a, t_real b);
void	*vec_divide_scalar(t_vector buffer, t_vector a, t_real b);
t_real	vec_size(const t_vector vec);
void	*vec_norm(t_vector buffer, t_vector vec);
t_real	vec_cosine_similarity(const t_vector a, const t_vector b);
void	*vec_min(t_vector buffer, t_vector a, t_vector b);
void	*vec_max(t_vector buffer, t_vector a, t_vector b);
void	*vec_set_zero(t_vector buffer);
int		is_vector_zero(const t_vector vec);
int		are_values_same(t_real value1, t_real value2);
#endif
