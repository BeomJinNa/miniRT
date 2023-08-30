/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:23:16 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 07:13:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int	trgb(int transparency, int red, int green, int blue);
int	transparency(int trgb);
int	red(int trgb);
int	green(int trgb);
int	blue(int trgb);
int	mix_color(int c1, int c2, int w1, int w2);
#endif
