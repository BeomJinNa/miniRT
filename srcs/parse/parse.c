/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:55:15 by dowon             #+#    #+#             */
/*   Updated: 2023/10/25 06:38:10 by bena             ###   ########.fr       */
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

static int	is_line_invalid(void *line)
{
	const char	*iter = line;
	const char	*word_start;

	if (*iter == ' ')
		return (0);
	while (*iter != '\0')
	{
		while (*iter == ' ')
		{
			++iter;
		}
		word_start = iter;
		while (*iter != '\0' && *iter != ' ')
		{
			if (*iter == ',' && !((iter[1] == '-' && ft_isdigit(iter[2]))
					|| ft_isdigit(iter[1])))
			{
				printf("error at <1>: %s\n", iter);
				return (1);
			}
			++iter;
		}
		if (word_start == iter)
		{
			printf("error at <3>: %s / %s\n", word_start, iter);
			return (1);
		}
		++iter;
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
		printf("failed to open file.\n");
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\0' || line[0] == '\n')
			free(line);
		else
			ft_lstadd_back(&lines, ft_lstnew(line));
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
	return (!ft_strncmp(str + (len_str - len_postfix), (char *)postfix,
			len_postfix));
}

void	print_vector(const char *prefix, t_vector v)
{
	printf("%s : (%f,%f,%f)", prefix, v[0], v[1], v[2]);
}

void	print_light_info(void *ptr)
{
	t_light*const	light = ptr;

	printf("[light]");
	print_vector("\n\tpos", light->position);
	print_vector("\n\trgb", light->color);
	printf("\n");
}

void	print_object_info(void *ptr)
{
	t_object*const	obj = ptr;
	if (obj->type == M_OBJECT_TYPE_PLANE)
	{
		printf("[plane]");
		print_vector("\n\tpos", obj->u_data.plane.position);
		print_vector("\n\tnormal", obj->u_data.plane.normal_unit);
		print_vector("\n\trgb", obj->texture.reflectance);
		printf("\n");
	}
	else if (obj->type == M_OBJECT_TYPE_CYLINDER)
	{
		printf("[cylinder]");
		print_vector("\n\tpos", obj->u_data.cylinder.position);
		print_vector("\n\tnormal", obj->u_data.cylinder.normal_unit);
		print_vector("\n\trgb", obj->texture.reflectance);
		printf("\n\theight: %f", obj->u_data.cylinder.height);
		printf("\n\tdiameter: %f\n", obj->u_data.cylinder.radius * (t_real)2.0);
		printf("\n");
	}
	else if (obj->type == M_OBJECT_TYPE_SPHERE)
	{
		printf("[sphere]");
		print_vector("\n\tpos", obj->u_data.sphere.position);
		print_vector("\n\trgb", obj->texture.reflectance);
		printf("\n\tdiameter: %f", obj->u_data.sphere.radius * (t_real)2.0);
		printf("\n");
	}
	else
	{
		printf("[unknown object type]\n");
	}
}

int	parse(char *filename, t_data *data)
{
	t_list	*file_content;

	data->objects = NULL;
	data->images = NULL;
	data->lights = NULL;
	data->objects = NULL;
	data->tree = NULL;
	if (!is_str_ends_with(filename, ".rt"))
		return (1);
	file_content = read_all_line(filename);
	ft_lstiter(file_content, remove_endl);
	if (lst_every(file_content, is_line_invalid)
		|| lst_every_arg(file_content, convert_line_to_obj, data))
	{
		ft_lstclear(&file_content, free);
		return (1);
	}
	/*
	printf("[ambient]\trgb : (%f,%f,%f)\n", data->ambient[0], data->ambient[1], data->ambient[2]);
	ft_lstiter(data->lights, (void (*)(void *))print_light_info);
	ft_lstiter(data->objects, print_object_info);
	*/
	return (0);
}
