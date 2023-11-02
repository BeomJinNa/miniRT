/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:56:39 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:06:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include "type.h"
# include "vector.h"

int		parse_normalized_vector(const char *line, t_vector vec);
int		parse_real_number(const char *str, t_real *real);
int		parse_unsigned_number(char *line, t_real *real);
int		parse_vector(const char *str, t_vector v);
int		parse_rgb(const char *str, t_vector rgb);
int		parse_degree(const char *line, t_real *real);
int		parse_ratio(const char *line, t_real *real);

#endif
