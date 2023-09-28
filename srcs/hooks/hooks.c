/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:22 by bena              #+#    #+#             */
/*   Updated: 2023/09/28 19:20:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks.h"
#include <stdlib.h>

int			close_window(t_status *stat);
static int	press_key(int keycode, t_status *stat);
static int	press_key2(int keycode, t_status *stat);

void	alloc_hooks(t_status *stat)
{
	mlx_hook(stat->win, ON_DESTROY, 0, close_window, stat);
	mlx_hook(stat->win, ON_KEYDOWN, 0, press_key, stat);
}

int	close_window(t_status *stat)
{
	if (stat->win != NULL)
		mlx_destroy_window(stat->mlx, stat->win);
	//free dynamic memories
	exit(0);
}

static int	press_key(int keycode, t_status *stat)
{
	if (keycode == KEY_ESCAPE)
		close_window(stat);
	else if (keycode == KEY_R)
		reset_settings(stat);
	return (press_key2(keycode, stat));
}

static int	press_key2(int keycode, t_status *stat)
{
	return (0);
}
