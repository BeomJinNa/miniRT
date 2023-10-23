/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:39:55 by dowon             #+#    #+#             */
/*   Updated: 2023/10/16 22:35:26 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**lst_to_str_array(t_list *lst, int lst_len)
{
	char**const	result = malloc(sizeof(char *) * (lst_len + 1));
	int			idx;

	if (result == NULL)
		return (NULL);
	idx = 0;
	while (idx < lst_len)
	{
		result[idx] = lst->content;
		lst = lst->next;
		++idx;
	}
	return (result);
}

char	**tokenize_str(char *str, const char token)
{
	char	*word_start;
	t_list	*word_list;
	int		list_len;

	word_list = NULL;
	list_len = 0;
	while (*str != '\0')
	{
		word_start = str;
		while (*str != '\0' && *str != token)
			++str;
		if (word_start != str)
		{
			ft_lstadd_back(&word_list,
				ft_lstnew(ft_substr(word_start, 0, str - word_start + 1)));
			++list_len;
		}
		while (*str == token)
			++str;
	}
	return (lst_to_str_array(word_list, list_len));
}
