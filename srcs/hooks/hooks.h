/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:38:24 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 05:22:44 by bena             ###   ########.fr       */
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
	KEY_A				= 0,
	KEY_S				= 1,
	KEY_D				= 2,
	KEY_F				= 3,
	KEY_H				= 4,
	KEY_G				= 5,
	KEY_Z				= 6,
	KEY_X				= 7,
	KEY_C				= 8,
	KEY_V				= 9,
	KEY_B				= 11,
	KEY_Q				= 12,
	KEY_W				= 13,
	KEY_E				= 14,
	KEY_R				= 15,
	KEY_Y				= 16,
	KEY_T				= 17,
	KEY_1				= 18,
	KEY_2				= 19,
	KEY_3				= 20,
	KEY_4				= 21,
	KEY_6				= 22,
	KEY_5				= 23,
	KEY_EQUAL			= 24,
	KEY_9				= 25,
	KEY_7				= 26,
	KEY_MINUS			= 27,
	KEY_8				= 28,
	KEY_0				= 29,
	KEY_RIGHTBRACKET	= 30,
	KEY_O				= 31,
	KEY_U				= 32,
	KEY_LEFTBRACKET		= 33,
	KEY_I				= 34,
	KEY_P				= 35,
	KEY_L				= 37,
	KEY_J				= 38,
	KEY_QUOTE			= 39,
	KEY_K				= 40,
	KEY_SEMICOLON		= 41,
	KEY_BACKSLASH		= 42,
	KEY_COMMA			= 43,
	KEY_SLASH			= 44,
	KEY_N				= 45,
	KEY_M				= 46,
	KEY_PERIOD			= 47,
	KEY_GRAVE			= 50,
	KEY_KEYPADDECIMAL	= 65,
	KEY_KEYPADMULTIPLY	= 67,
	KEY_KEYPADPLUS		= 69,
	KEY_KEYPADCLEAR		= 71,
	KEY_KEYPADDIVIDE	= 75,
	KEY_KEYPADENTER		= 76,
	KEY_KEYPADMINUS		= 78,
	KEY_KEYPADEQUALS	= 81,
	KEY_KEYPAD0			= 82,
	KEY_KEYPAD1			= 83,
	KEY_KEYPAD2			= 84,
	KEY_KEYPAD3			= 85,
	KEY_KEYPAD4			= 86,
	KEY_KEYPAD5			= 87,
	KEY_KEYPAD6			= 88,
	KEY_KEYPAD7			= 89,
	KEY_KEYPAD8			= 91,
	KEY_KEYPAD9			= 92,
	KEY_RETURN			= 36,
	KEY_TAB				= 48,
	KEY_SPACE			= 49,
	KEY_DELETE			= 51,
	KEY_ESCAPE			= 53,
	KEY_COMMAND			= 55,
	KEY_SHIFT			= 56,
	KEY_CAPSLOCK		= 57,
	KEY_OPTION			= 58,
	KEY_CONTROL			= 59,
	KEY_RIGHTCOMMAND	= 54,
	KEY_RIGHTSHIFT		= 60,
	KEY_RIGHTOPTION		= 61,
	KEY_RIGHTCONTROL	= 62,
	KEY_FUNCTION		= 63,
	KEY_F17				= 64,
	KEY_VOLUMEUP		= 72,
	KEY_VOLUMEDOWN		= 73,
	KEY_MUTE			= 74,
	KEY_F18				= 79,
	KEY_F19				= 80,
	KEY_F20				= 90,
	KEY_F5				= 96,
	KEY_F6				= 97,
	KEY_F7				= 98,
	KEY_F3				= 99,
	KEY_F8				= 100,
	KEY_F9				= 101,
	KEY_F11				= 103,
	KEY_F13				= 105,
	KEY_F16				= 106,
	KEY_F14				= 107,
	KEY_F10				= 109,
	KEY_F12				= 111,
	KEY_F15				= 113,
	KEY_HELP			= 114,
	KEY_HOME			= 115,
	KEY_PAGEUP			= 116,
	KEY_FORWARDDELETE	= 117,
	KEY_F4				= 118,
	KEY_END				= 119,
	KEY_F2				= 120,
	KEY_PAGEDOWN		= 121,
	KEY_F1				= 122,
	KEY_LEFTARROW		= 123,
	KEY_RIGHTARROW		= 124,
	KEY_DOWNARROW		= 125,
	KEY_UPARROW			= 126
};

void	reset_settings(t_stat *stat);
void	camera_move_forward(t_stat *stat);
void	camera_move_backward(t_stat *stat);
void	camera_move_leftward(t_stat *stat);
void	camera_move_rightward(t_stat *stat);
void	camera_move_upward(t_stat *stat);
void	camera_move_downward(t_stat *stat);
void	camera_rotate_up(t_stat *stat);
void	camera_rotate_down(t_stat *stat);
void	camera_rotate_left(t_stat *stat);
void	camera_rotate_right(t_stat *stat);
void	zoom_out(t_stat *stat);
void	zoom_in(t_stat *stat);
#endif
