/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:07:33 by dowon             #+#    #+#             */
/*   Updated: 2023/10/28 22:01:06 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <stdlib.h>

void	recursive_free(void *ptr, int dimension);
size_t	ptr_len(void **ptr);
int		is_str_ends_with(char *str, const char *postfix);
int		lst_every_arg(const t_list *lst, int (*f)(void *, void *), void *arg);
int		lst_every(const t_list *lst, int (*f)(void *));

#endif