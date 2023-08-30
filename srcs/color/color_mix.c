/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:29:43 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 11:40:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	mix_color(int c1, int c2, int w1, int w2)
{
	int	total;
	int	t;
	int	r;
	int	g;
	int	b;

	total = w1 + w2;
	if (total == 0)
	{
		w1 = 1;
		w2 = 1;
		total = 2;
	}
	t = (transparency(c1) * w1 + transparency(c2) * w2) / total;
	r = (red(c1) * w1 + red(c2) * w2) / total;
	g = (green(c1) * w1 + green(c2) * w2) / total;
	b = (blue(c1) * w1 + blue(c2) * w2) / total;
	return (trgb(t, r, g, b));
}
