/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:18:40 by dowon             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"
#include "../parse.h"

static int	validate_rgb(t_vector rgb)
{
	return (0 <= rgb[0] && rgb[0] <= 255.0
		&& 0 <= rgb[1] && rgb[1] <= 255.0
		&& 0 <= rgb[2] && rgb[2] <= 255.0);
}

int	parse_rgb(const char *str, t_vector rgb)
{
	int	result;

	result = parse_vector(str, rgb);
	if (result || !validate_rgb(rgb))
	{
		parse_error("failed to validate rgb : ", str);
		parse_error("\tL each channel of rgb must be in range : ",
			"[0.0, 255.0]");
		result = 1;
	}
	return (result);
}
