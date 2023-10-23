/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 20:40:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAT_H
# define STAT_H

# include "tree.h"

# define M_VECTOR_MIN_SCALE 1e-5f

enum e_config
{
	M_WINDOW_WIDTH_MIN = 300,
	M_WINDOW_WIDTH_MAX = 2550,
	M_WINDOW_HEIGHT_MIN = 300,
	M_WINDOW_HEIGHT_MAX = 1380,
	M_TREE_MAX_DEPTH = 10,
	M_TREE_MIN_LEAF_SIZE = 1,
	M_SCATTER_SAMPLE_SIZE = 10,
	M_SCATTER_MAX_DEPTH = 2,
};

typedef struct s_data	t_data;
typedef struct s_status	t_stat;

struct s_data
{
	t_tree		*tree;
	t_list 		*objects;
	t_list		*lights;
	t_list		*images;
	t_cam		cam;
	t_vector	ambient;
};

struct s_status
{
	char	*title;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		win_width_2;
	int		win_height_2;
	t_data	data;
};

void	free_malloced_memories(t_stat *stat);
void	draw_image(t_stat *stat);
#endif
