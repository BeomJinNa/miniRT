/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:56:39 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "type.h"
# include "vector.h"
# include "stat.h"
# include <stdlib.h>

enum e_parse_error {
	PARSE_SUCCESS,
	PARSE_INVALID_FILENAME,
	PARSE_FAILED_TO_READ_FILE,
	PARSE_A_REQUIRED,
	PARSE_A_TOO_MANY,
	PARSE_C_REQUIRED,
	PARSE_C_TOO_MANY,
	PARSE_L_REQUIRED,
	PARSE_L_TOO_MANY,
};

int		parse(char *filename, t_data *data);
void	parse_error(const char *str1, const char *str2);
int		is_acl_unique(t_list *file_content);

#endif