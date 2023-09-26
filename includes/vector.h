/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:47:36 by bena              #+#    #+#             */
/*   Updated: 2023/09/26 19:40:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "type.h"

typedef t_real	t_vector[3];

void	*vec_copy(t_vector destination, t_vector source);
void	*vec_add(t_vector buffer, t_vector a, t_vector b);
void	*vec_add_elem(t_vector buffer, t_vector a, t_real b);
void	*vec_subtract(t_vector buffer, t_vector a, t_vector b);
void	*vec_subtract_elem(t_vector buffer, t_vector a, t_real b);
t_real	vec_dot_product(t_vector a, t_vector b);
void	*vec_cross_product(t_vector buffer, t_vector a, t_vector b);
void	*vec_product_elem(t_vector buffer, t_vector a, t_real b);
void	*vec_divide_elem(t_vector buffer, t_vector a, t_real b);
t_real	vec_size(t_vector vec);
void	*vec_norm(t_vector buffer, t_vector vec);
t_real	vec_cosine_similarity(t_vector a, t_vector b);
void	*vec_min(t_vector buffer, t_vector a, t_vector b);
void	*vec_max(t_vector buffer, t_vector a, t_vector b);
#endif
