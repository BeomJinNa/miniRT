/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:39:04 by bena              #+#    #+#             */
/*   Updated: 2023/10/23 08:45:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*listdup(t_list *list)
{
	t_list	*output;
	t_list	*ptr;
	t_list	*temp;

	output = NULL;
	ptr = list;
	while (ptr != NULL)
	{
		temp = ft_lstnew(ptr->content);
		if (temp == NULL)
		{
			ft_lstclear(&output, NULL);
			return (NULL);
		}
		ft_lstadd_back(&output, temp);
		ptr = ptr->next;
	}
	return (output);
}
