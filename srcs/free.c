/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:14:12 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 19:03:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include <stdlib.h>

void	free_malloced_memories(t_stat *stat)
{
		remove_tree(&stat->data.tree);
		ft_lstclear(&stat->data.objects, free);
		ft_lstclear(&stat->data.lights, free);
		ft_lstclear(&stat->data.images, free);
		if (stat->data.cam.image.data != NULL)
			free(stat->data.cam.image.data);
}
