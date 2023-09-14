/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:47:36 by bena              #+#    #+#             */
/*   Updated: 2023/09/13 03:01:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "type.h"

typedef t_real vector[3];

void	vec_add(vector buffer, vector a, vector b);
void	vec_subtract(vector buffer, vector a, vector b);
t_real	vec_dot_product(vector a, vector b);
void	vec_cross_product(vector buffer, vector a, vector b);
void	vec_norm(vector buffer, vector vec);
#endif
