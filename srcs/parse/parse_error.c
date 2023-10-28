/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:16 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 21:09:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	print_to_stderr(const char *str1, const char *str2)
{
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
}

void	print_parse_error(const char *str1, const char *str2)
{
	write(2, "Error\nparse error : ", 21);
	print_to_stderr(str1, str2);
	write(2, "\n", 1);
}
