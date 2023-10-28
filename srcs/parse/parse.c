/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:55:15 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 19:43:58 by dowon            ###   ########.fr       */
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

static int	is_line_invalid(void *pline)
{
	const char	*line = pline;

	if (*line == ' ')
	{
		print_parse_error("line start with space : ", line);
		return (1);
	}
	if (ft_strlen(line) < 2)
	{
		print_parse_error("line is too short : ", line);
		return (1);
	}
	if (line[ft_strlen(line)] == ' ')
	{
		print_parse_error("line ends with space : ", line);
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
		print_parse_error("failed to open file", filename);
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
		print_parse_error("failed to read file.\n", "");
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

int	count_ACL(void *pline, void *pcount)
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

int	is_ACL_unique(t_list *file_content)
{
	int	acl_count[3];

	ft_memset(acl_count, 0, sizeof(acl_count));
	lst_every_arg(file_content, count_ACL, acl_count);
	if (acl_count[0] == 0)
		print_parse_error("Ambient light is required in .rt format.", "");
	else if (acl_count[0] > 1)
		print_parse_error("Ambient light is more than one .rt format.", "");
	if (acl_count[1] == 0)
		print_parse_error("Camera is required in .rt format.", "");
	else if (acl_count[1] > 1)
		print_parse_error("Camera is more than one .rt format.", "");
	if (acl_count[2] == 0)
		print_parse_error("Light is required in .rt format.", "");
	else if (!M_BONUS && acl_count[2] > 1)
		print_parse_error("Light is more than one .rt format.", "");
	if ((!M_BONUS && acl_count[2] != 1) || (M_BONUS && acl_count[2] == 0))
		return (0);
	return (acl_count[0] == 1 && acl_count[1] == 1);
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
	{
		print_parse_error("filename should ends with .rt.\n", "");
		return (1);
	}
	file_content = read_all_line(filename);
	if (file_content == NULL)
		return (1);
	ft_lstiter(file_content, remove_endl);
	if (
		lst_every(file_content, is_line_invalid)
		|| !is_ACL_unique(file_content)
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
