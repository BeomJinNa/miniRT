# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:31:16 by dowon             #+#    #+#              #
#    Updated: 2023/10/23 16:35:02 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LFLAGS = -L../../libft -lft
IFLAGS = -I../../includes
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter $(IFLAGS)
NAME = parse_test
SRCS = converter/convert_line_to_ambient_light.c \
	converter/convert_line_to_camera.c \
	converter/convert_line_to_cylinder.c \
	converter/convert_line_to_light.c \
	converter/convert_line_to_obj.c \
	converter/convert_line_to_plane.c \
	converter/convert_line_to_sphere.c \
	converter/rgb_to_ratio.c \
	parse.c \
	parse.test.c \
	parse_utils/parse_degree.c \
	parse_utils/parse_normalized_vector.c \
	parse_utils/parse_ratio.c \
	parse_utils/parse_real_number.c \
	parse_utils/parse_rgb.c \
	parse_utils/parse_unsigned_number.c \
	parse_utils/parse_vector.c \
	tokenize.c \
	utils/ptr_utils.c \
	../object/init_object.c \
	../object/set_bounding_volume.c \
	../vector/vector_condition.c \
	../vector/vector_constant.c \
	../vector/vector_create.c \
	../vector/vector_elementwise_operation.c \
	../vector/vector_operation.c \
	../vector/vector_scalar_operation.c \
	../vector/vector_transformation.c

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