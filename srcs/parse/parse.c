/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:55:15 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 19:45:54 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "stat.h"
#include "converter/converter.h"
#include "utils/utils.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int	is_line_invalid(void *pline)
{
	const char	*line = pline;

	if (*line == ' ')
	{
		parse_error("line start with space : ", line);
		return (1);
	}
	if (ft_strlen(line) < 2)
	{
		parse_error("line is too short : ", line);
		return (1);
	}
	if (line[ft_strlen(line)] == ' ')
	{
		parse_error("line ends with space : ", line);
		return (1);
	}
	return (0);
}

void	remove_endl(void *str)
{
	char	*cstr;
	size_t	len;

	cstr = str;
	len = ft_strlen(cstr);
	if (cstr[len - 1] == '\n')
		cstr[len - 1] = '\0';
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

	lines = NULL;
	if (fd == -1)
	{
		parse_error("failed to open file : ", filename);
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
			free(line);
		else
			ft_lstadd_back(&lines, ft_lstnew(line));
	}
	close(fd);
	if (lines == NULL)
		parse_error("failed to read file : ", filename);
	return (lines);
}

void	init_data(t_data *data)
{
	data->lights = NULL;
	data->objects = NULL;
	data->images = NULL;
	data->tree = NULL;
}

int	parse(char *filename, t_data *data)
{
	t_list	*file_content;

	init_data(data);
	if (!is_str_ends_with(filename, ".rt"))
	{
		parse_error("filename should ends with .rt.", "");
		return (1);
	}
	file_content = read_all_line(filename);
	if (file_content == NULL)
		return (1);
	ft_lstiter(file_content, remove_endl);
	if (lst_every(file_content, is_line_invalid) || !is_acl_unique(file_content)
		|| lst_every_arg(file_content, convert_line_to_obj, data))
	{
		ft_lstclear(&file_content, free);
		return (1);
	}
	ft_lstclear(&file_content, free);
	// if (data->objects == NULL)
	// {
	// 	parse_error("No objects founded in file : ", filename);
	// 	return (1);
	// }
	return (0);
}
