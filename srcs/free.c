/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:14:12 by bena              #+#    #+#             */
/*   Updated: 2023/10/28 17:49:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stat.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	free_malloced_memories(t_stat *stat)
{
	remove_tree(&stat->data.tree);
	ft_lstclear(&stat->data.objects, free);
	ft_lstclear(&stat->data.lights, free);
	ft_lstclear(&stat->data.images, free);
	if (stat->data.cam.image.data != NULL)
		free(stat->data.cam.image.data);
}

void	print_error(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	write(2, "Error\n", 6);
	write(2, str, ptr - str);
}
