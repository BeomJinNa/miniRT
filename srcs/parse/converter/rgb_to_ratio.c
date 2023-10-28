/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_ratio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:20:44 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 18:05:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_real	*rgb_to_ratio(t_real *buff, t_real *rgb, t_real ratio)
{
	return (vec_product_scalar(buff,
			vec_divide_scalar(buff, rgb, 255.0), ratio));
}
