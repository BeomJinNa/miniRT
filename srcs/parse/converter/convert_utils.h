/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:38:22 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:06:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_UTILS_H
# define CONVERT_UTILS_H

# include "stat.h"
# include "object.h"
# include <stddef.h>

t_real		*rgb_to_ratio(t_real *buff, t_real *rgb, t_real ratio);

int			convert_line_to_ambient(char *line, t_data *data);
int			convert_line_to_camera(char *line, t_data *data);
int			convert_line_to_light(char *line, t_data *data);
t_object	*convert_line_to_sphere(char *line);
t_object	*convert_line_to_plane(char *line);
t_object	*convert_line_to_cylinder(char *line);
int			parse_additional(char **words, size_t base_form_len, t_object *obj);

#endif
