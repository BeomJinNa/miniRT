/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acl_unique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:44:02 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "parse.h"
#include "stat.h"
#include "libft.h"

static int	count_acl(void *pline, void *pcount)
{
	char*const	line = pline;
	int*const	count = pcount;

	if (ft_strncmp("A ", line, 2) == 0)
		++count[0];
	else if (ft_strncmp("C ", line, 2) == 0)
		++count[1];
	else if (ft_strncmp("L ", line, 2) == 0)
		++count[2];
	return (0);
}

int	is_acl_unique(t_list *file_content)
{
	int	acl_count[3];

	ft_memset(acl_count, 0, sizeof(acl_count));
	lst_every_arg(file_content, count_acl, acl_count);
	if (acl_count[0] == 0)
		parse_error("Ambient light is required in .rt format.", "");
	else if (acl_count[0] > 1)
		parse_error("Ambient light is more than one .rt format.", "");
	if (acl_count[1] == 0)
		parse_error("Camera is required in .rt format.", "");
	else if (acl_count[1] > 1)
		parse_error("Camera is more than one .rt format.", "");
	if (acl_count[2] == 0)
		parse_error("Light is required in .rt format.", "");
	else if (!M_BONUS && acl_count[2] > 1)
		parse_error("Light is more than one .rt format.", "");
	if ((!M_BONUS && acl_count[2] != 1) || (M_BONUS && acl_count[2] == 0))
		return (0);
	return (acl_count[0] == 1 && acl_count[1] == 1);
}
