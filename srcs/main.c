/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/10/25 06:36:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include "parse/parse.h"
#include <stdio.h>

void		run_mlx(t_stat *stat);
void		free_malloced_memories(t_stat *stat);
static void	set_window_size(int ac, char **av, t_stat *stat);

int	main(int argc, char **argv)
{
	t_stat	stat;

	ft_memset(&stat, 0, sizeof(stat));
	if (argc != 2 && argc != 4)
		return (-1);
	if (parse(argv[1], &stat.data))
	{
		printf("parse error\n");
		return (1);
	}
	set_window_size(argc, argv, &stat);
	run_mlx(&stat);
	free_malloced_memories(&stat);
	return (0);
}

static void	set_window_size(int argc, char **argv, t_stat *stat)
{
	if (argc == 2)
	{
		stat->win_width = 1200;
		stat->win_height = 800;
	}
	else if (argc == 4)
	{
		stat->win_width = ft_atoi(argv[2]);
		stat->win_height = ft_atoi(argv[3]);
	}
	if (stat->win_width < M_WINDOW_WIDTH_MIN)
		stat->win_width = M_WINDOW_WIDTH_MIN;
	if (stat->win_width > M_WINDOW_WIDTH_MAX)
		stat->win_width = M_WINDOW_WIDTH_MAX;
	if (stat->win_height < M_WINDOW_HEIGHT_MIN)
		stat->win_height = M_WINDOW_HEIGHT_MIN;
	if (stat->win_height > M_WINDOW_HEIGHT_MAX)
		stat->win_height = M_WINDOW_HEIGHT_MAX;
	stat->win_width_2 = stat->win_width / 2;
	stat->win_height_2 = stat->win_height / 2;
}
