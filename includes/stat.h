/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/10/28 01:27:16 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAT_H
# define STAT_H

# include "tree.h"

# define M_VECTOR_MIN_SCALE 0.00001f
# define M_DEFAULT_PREVIEW_SCALE 0.08f
# define M_SCALING_SPOT_LIGHT 100
# define M_EXPOSURE_MAX 100000.0f
# define M_EXPOSURE_MIN 0.001f
# define M_MOVING_DISTANCE 10.0f

enum e_config
{
	M_WINDOW_WIDTH_MIN = 300,
	M_WINDOW_WIDTH_MAX = 2550,
	M_WINDOW_HEIGHT_MIN = 300,
	M_WINDOW_HEIGHT_MAX = 1380,
	M_TREE_MAX_DEPTH = 10,
	M_TREE_MIN_LEAF_SIZE = 1,
	M_SCATTER_SAMPLE_SIZE = 5,
	M_SCATTER_MAX_DEPTH = 2,
};

typedef struct s_data	t_data;
typedef struct s_status	t_stat;

struct s_data
{
	t_tree		*tree;
	t_list		*objects;
	t_list		*lights;
	t_list		*images;
	t_cam		cam;
	t_vector	ambient;
	t_vector	cam_init_position;
	t_vector	cam_init_direction;
	t_real		cam_init_fov;
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
void	render_map(t_stat *stat, t_real scale_factor);
void	print_cam_info(t_stat *stat);
void	delete_cam_info(void);
void	print_manual(void);
void	re_render_image_on_mlx(t_stat *stat);
void	render_hires_image_on_mlx(t_stat *stat);
void	re_draw_image_on_mlx(t_stat *stat);
#endif
