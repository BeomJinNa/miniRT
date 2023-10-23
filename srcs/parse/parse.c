/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:55:15 by dowon             #+#    #+#             */
/*   Updated: 2023/10/23 16:28:46 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "tree.h"
#include "vector.h"
#include "parse.h"
#include "stat.h"
#include "converter/converter.h"
#include "utils/utils.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

// const t_rt_object_format	formats[] = {
// {"A", 2, {F_RT_RATIO, F_RT_RGB}, 0, {}},
// {"C", 3, {F_RT_VEC, F_RT_N_VEC, F_RT_NUM}, 0, {}},
// {"L", 3, {F_RT_VEC, F_RT_NUM, F_RT_RGB}, 0, {}},
// {"sp", 3, {F_RT_RATIO, F_RT_NUM, F_RT_RGB}, 0, {}},
// {"pl", 3, {F_RT_RATIO, F_RT_N_VEC, F_RT_RGB}, 0, {}},
// {"cy", 3, {F_RT_RATIO, F_RT_N_VEC, F_RT_NUM, F_RT_NUM, F_RT_RGB}, 0, {}},
// {"co", 3, {F_RT_RATIO, F_RT_N_VEC, F_RT_NUM, F_RT_NUM, F_RT_RGB}, 0, {}},
// };

static int	validate_line(const char*const line)
{
	const char	*iter = line;
	const char	*word_start;

	if (*iter == ' ')
		return (0);
	while (*iter != '\0' && *iter != '\n')
	{
		while (*iter == ' ')
		{
			++iter;
		}
		word_start = iter;
		while (*iter != '\0' && *iter != '\n' && *iter != ' ')
		{
			if (*iter == ',' && ft_isalnum(*(iter + 1)))
			{
				return (0);
			}
			++iter;
		}
		if (word_start == iter)
			return (0);
		++iter;
	}
	return (1);
}

/*
Each type of element can be separated by one or more line break(s).
Each type of information from an element
	can be separated by one or more space(s).
Each type of element can be set in any order in the file.
Elements which are defined by a capital letter
	can only be declared once in the scene.

<information> : type identifier or property of element.
	ex) "A", "R,G,B" "Radius", "Ratio" ...
<element> : set of information of an object.
	ex) A 0.2 255,255,255

<element>
	-> <information>[one or more space(s)]<information>...<information>
<file>
	-> <element>[one or more line break(s)]<element>...<element>
*/
t_list	*read_all_line(char *filename)
{
	const int	fd = open(filename, O_RDONLY);
	char		*line;
	t_list		*lines;

	if (fd == -1)
	{
		printf("failed to open file.\n");
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\0')
			ft_lstadd_back(&lines, ft_lstnew(line));
		free(line);
	}
	close(fd);
	return (lines);
}

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
	return (!!ft_strncmp(str + (len_str - len_postfix), (char *)postfix,
			len_str - len_postfix + 1));
}

int	parse(char *filename, t_data *data)
{
	t_list	*file_content;

	if (!is_str_ends_with(filename, ".rt"))
		return (1);
	file_content = read_all_line(filename);
	if (lst_every(file_content, (int (*)(void *))validate_line))
	{
		ft_lstclear(&file_content, free);
		return (1);
	}
	if (lst_every_arg(file_content, (int (*)(void *, void *))convert_line_to_obj, data))
	{
		ft_lstclear(&file_content, free);
		return (1);
	}
	return (0);
}
