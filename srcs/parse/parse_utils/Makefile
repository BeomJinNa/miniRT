# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:31:16 by dowon             #+#    #+#              #
#    Updated: 2023/10/23 16:16:12 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LFLAGS = -L../../../libft -lft
IFLAGS = -I../../../includes
CFLAGS = -Wall -Wextra -Werror $(IFLAGS)
NAME = parse_test
SRCS = parse.test.c parse_degree.c parse_normalized_vector.c parse_ratio.c \
	parse_real_number.c parse_rgb.c parse_vector.c \
	../utils/ptr_utils.c ../../vector/vector_condition.c ../../vector/vector_operation.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.PHONY: all

%.o: %.c
	CC $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

.PHONY: clean

fclean: clean
	rm -f $(NAME)

.PHONY: fclean

re:
	make fclean
	make all

.PHONY: re