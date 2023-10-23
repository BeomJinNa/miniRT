/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:07:33 by dowon             #+#    #+#             */
/*   Updated: 2023/10/23 16:28:54 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
recursive free for null-terminated pointer.
usage)
char **word = ft_split("split this line.", ' ');
recursive_free(word, 2);
*/
void	recursive_free(void *ptr, int dimension)
{
	void	**dptr;

	if (dimension == 0)
		return ;
	if (dimension > 1)
	{
		dptr = ptr;
		while (*dptr != NULL)
		{
			recursive_free(*dptr, dimension - 1);
			++dptr;
		}
	}
	free(ptr);
}

/*
get length of null-terminated pointer array
*/
size_t	ptr_len(void **ptr)
{
	void	**iter;

	iter = ptr;
	while (*iter != NULL)
		++iter;
	return (iter - ptr);
}
