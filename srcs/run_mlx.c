/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:50:53 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 13:07:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stat.h"
#include "libft.h"

int			close_window(t_stat *stat);
void		alloc_hooks(t_stat *stat);
void		print_data(t_data *data);
static void	init_mlx(t_stat *stat);
static int	create_map(t_stat *stat);

void	run_mlx(t_stat *stat)
{
	init_mlx(stat);
	if (stat->win == NULL)
		close_window(stat);
	alloc_hooks(stat);
	if (create_map(stat))
		close_window(stat);
	print_data(&stat->data);
	//draw picture
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

static int	create_map(t_stat *stat)
{
	t_list	*obj_list;
	t_tree	*root;

	obj_list = listdup(stat->data.objects);
	if (obj_list == NULL)
		return (-1);
	root = init_tree(obj_list);
	if (root == NULL)
	{
		ft_lstclear(&obj_list, NULL);
		return (-1);
	}
	if (build_tree(root))
		return (-1);
	return (0);
}
