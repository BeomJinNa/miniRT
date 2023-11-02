/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:55:15 by dowon             #+#    #+#             */
/*   Updated: 2023/11/02 20:11:28 by dowon            ###   ########.fr       */
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

static t_list	*read_all_line(char *filename)
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

int	check_object(t_data *data)
{
	if (data->objects == NULL)
	{
		parse_error("No object found", "");
		return (0);
	}
	return (1);
}

void	init_data(t_data *data)
{
	data->lights = NULL;
	data->objects = NULL;
	data->images = NULL;
	data->tree = NULL;
	data->cam.image.data = NULL;
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
		|| lst_every_arg(file_content, convert_line_to_obj, data)
		|| !check_object(data))
	{
		if (data->objects)
			ft_lstclear(&data->objects, free);
		if (data->lights)
			ft_lstclear(&data->lights, free);
		ft_lstclear(&file_content, free);
		return (1);
	}
	ft_lstclear(&file_content, free);
	return (0);
}
