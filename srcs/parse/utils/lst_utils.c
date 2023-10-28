/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:59:09 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 21:59:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lst_every(const t_list *lst, int (*f)(void *))
{
	const t_list	*iter;
	int				is_failed;

	iter = lst;
	while (iter)
	{
		is_failed = f(iter->content);
		if (is_failed)
			return (1);
		iter = iter->next;
	}
	return (0);
}

int	lst_every_arg(const t_list *lst, int (*f)(void *, void *), void *arg)
{
	const t_list	*iter;
	int				is_failed;

	iter = lst;
	while (iter)
	{
		is_failed = f(iter->content, arg);
		if (is_failed)
			return (1);
		iter = iter->next;
	}
	return (0);
}
