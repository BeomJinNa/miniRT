/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:47:36 by bena              #+#    #+#             */
/*   Updated: 2023/09/25 21:35:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "type.h"

typedef t_real vector[3];

void	*vec_copy(vector destination, vector source);
void	*vec_add(vector buffer, vector a, vector b);
void	*vec_add_elem(vector buffer, vector a, t_real b);
void	*vec_subtract(vector buffer, vector a, vector b);
void	*vec_subtract_elem(vector buffer, vector a, t_real b);
t_real	vec_dot_product(vector a, vector b);
void	*vec_cross_product(vector buffer, vector a, vector b);
void	*vec_product_elem(vector buffer, vector a, t_real b);
void	*vec_divide_elem(vector buffer, vector a, t_real b);
t_real	vec_size(vector vec);
void	*vec_norm(vector buffer, vector vec);
t_real	vec_cosine_similarity(vector a, vector b);
#endif
