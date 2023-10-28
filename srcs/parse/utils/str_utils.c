/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:43:06 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 21:43:26 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	is_str_ends_with(char *str, const char *postfix)
{
	size_t	len_str;
	size_t	len_postfix;

	if (str == NULL || postfix == NULL)
		return (0);
	len_str = ft_strlen(str);
	len_postfix = ft_strlen(postfix);
	if (len_str < len_postfix)
		return (0);
	return (!ft_strncmp(str + (len_str - len_postfix), (char *)postfix,
			len_postfix));
}
