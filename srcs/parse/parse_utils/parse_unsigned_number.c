/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:19:54 by dowon             #+#    #+#             */
/*   Updated: 2023/10/20 22:21:32 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

int	parse_unsigned_number(char *line, t_real *real)
{
	return (parse_real_number(line, real) && 0.0 <= *real);
}
