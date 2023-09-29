/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:22 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 17:42:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks.h"
#include <stdlib.h>

int			close_window(t_stat *stat);
static int	press_key(int keycode, t_stat *stat);
static int	press_key2(int keycode, t_stat *stat);

void	alloc_hooks(t_stat *stat)
{
	mlx_hook(stat->win, ON_DESTROY, 0, close_window, stat);
	mlx_hook(stat->win, ON_KEYDOWN, 0, press_key, stat);
}

int	close_window(t_stat *stat)
{
	if (stat->win != NULL)
		mlx_destroy_window(stat->mlx, stat->win);
	free_malloced_memories(stat);
	exit(0);
}

static int	press_key(int keycode, t_stat *stat)
{
	if (keycode == KEY_ESCAPE)
		close_window(stat);
	else if (keycode == KEY_R)
		reset_settings(stat);
	return (press_key2(keycode, stat));
}

static int	press_key2(int keycode, t_stat *stat)
{
	return (0);
}
