/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:50:53 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 20:40:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stat.h"
#include "libft.h"
#include <stdlib.h>

int			close_window(t_stat *stat);
void		alloc_hooks(t_stat *stat);
void		print_data(t_data *data);
void		render_map(t_stat *stat);
static void	init_mlx(t_stat *stat);
static int	create_map(t_stat *stat);
static int	fail_creating_map(void *pointer, t_list *list);

void	run_mlx(t_stat *stat)
{
	init_mlx(stat);
	if (stat->win == NULL)
		close_window(stat);
	alloc_hooks(stat);
	if (create_map(stat))
		close_window(stat);
	print_data(&stat->data);
	render_map(stat);
	draw_image(stat);
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

	if (stat->data.cam.image.size_height < 1
		|| stat->data.cam.image.size_width < 1)
		return (-1);
	stat->data.cam.image.data = (t_vector *)malloc(sizeof(t_vector)
			* stat->data.cam.image.size_width
			* stat->data.cam.image.size_height);
	if (stat->data.cam.image.data == NULL)
		return (-1);
	obj_list = listdup(stat->data.objects);
	if (obj_list == NULL)
		return (fail_creating_map(stat->data.cam.image.data, NULL));
	root = init_tree(obj_list);
	if (root == NULL)
		return (fail_creating_map(stat->data.cam.image.data, obj_list));
	if (build_tree(root))
		return (fail_creating_map(stat->data.cam.image.data, NULL));
	stat->data.tree = root;
	return (0);
}

static int	fail_creating_map(void *pointer, t_list *list)
{
	if (pointer != NULL)
		free(pointer);
	if (list != NULL)
		ft_lstclear(&list, NULL);
	return (-1);
}
