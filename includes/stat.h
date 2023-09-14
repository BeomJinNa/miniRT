/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/09/13 00:13:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAT_H
# define STAT_H

enum e_config
{
	M_WINDOW_WIDTH_MIN = 300,
	M_WINDOW_WIDTH_MAX = 2550,
	M_WINDOW_HEIGHT_MIN = 300,
	M_WINDOW_HEIGHT_MAX = 1380
};

typedef struct s_status
{
	char	*title;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		win_width_2;
	int		win_height_2;
	int		down_sampling_ratio;
}	t_status;
#endif
