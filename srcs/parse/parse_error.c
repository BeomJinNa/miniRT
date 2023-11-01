/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:16 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	parse_error(const char *str1, const char *str2)
{
	static int	is_first_error = 1;

	if (is_first_error)
	{
		is_first_error = 0;
		write(2, "Error\n<parse error>\n", 21);
	}
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
}
