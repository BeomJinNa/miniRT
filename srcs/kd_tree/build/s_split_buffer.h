/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_split_buffer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:45:18 by bena              #+#    #+#             */
/*   Updated: 2023/09/22 03:53:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SPLIT_BUFFER_H
# define S_SPLIT_BUFFER_H

# include "type.h"

typedef struct s_split_buffer
{
	int		total;
	int		included;
	int		remainder;
	int		axis;
	t_real	divider;
	t_real	cost;
}	t_sp_buffer;
#endif
