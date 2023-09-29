/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:38:24 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 17:16:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "stat.h"

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_keycodes
{
	KEY_ESCAPE = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_H = 4,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_I = 34,
	KEY_O = 31,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_C = 8,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_R = 15
};

void	reset_settings(t_stat *stat);
#endif
