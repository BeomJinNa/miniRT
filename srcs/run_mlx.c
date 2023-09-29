/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:50:53 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 18:20:04 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stat.h"
#include <stddef.h>

int			close_window(t_stat *stat);
void		alloc_hooks(t_stat *stat);
static void	init_mlx(t_stat *stat);

void	run_mlx(t_stat *stat)
{
	init_mlx(stat);
	if (stat->win == NULL)
		close_window(stat);
	alloc_hooks(stat);
//	DATA_INIT
//
//	if (INIT_FAILED)
//		close_window(stat);
//
//	mlx_loop_hook(stat->mlx, DRAW_PICTURE, stat);
	mlx_loop(stat->mlx);
}

static void	init_mlx(t_stat *stat)
{
	stat->title = "miniRT";
	stat->mlx = NULL;
	stat->win = NULL;
	stat->mlx = mlx_init();
	if (stat->mlx != NULL)
		stat->win = mlx_new_window(stat->mlx, stat->win_width, stat->win_height,
				stat->title);
}
