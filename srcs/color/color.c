/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:23:16 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 04:59:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	trgb(int transparency, int red, int green, int blue)
{
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

int	transparency(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	blue(int trgb)
{
	return (trgb & 0xFF);
}
