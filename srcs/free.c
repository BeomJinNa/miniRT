/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:14:12 by bena              #+#    #+#             */
/*   Updated: 2023/09/29 17:40:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include <stdlib.h>

void	free_malloced_memories(t_stat *stat)
{
	if (stat->data != NULL)
	{
		remove_tree(&stat->data->tree);
		ft_lstclear(&stat->data->objects, free);
		ft_lstclear(&stat->data->lights, free);
		ft_lstclear(&stat->data->images, free);
		free(stat->data);
	}
}
