/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bv.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:39:48 by bena              #+#    #+#             */
/*   Updated: 2023/09/26 22:40:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_BV_H
# define SET_BV_H

# include "object.h"

void	set_bv_on_plane(t_object *plane);
void	set_bv_on_cylinder(t_object *cylinder);
void	set_bv_on_cone(t_object *cone);
#endif
