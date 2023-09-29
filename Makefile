#parameters====================================================================

CC			= cc

COMMONFLAGS	=

CFLAGS		= $(COMMONFLAGS) -Wall -Wextra -Werror -Wno-unused-parameter -g

LDFLAGS		= $(COMMONFLAGS) \
			  $(foreach lib, $(TARGET_LIBDIR), -L$(lib)) \
			  $(foreach arch, $(TARGET_ARCH), -l$(arch))

NAME		= miniRT

INCLUDE		= includes/

#libraries=====================================================================

LIBDIR		= libft/ \
			  mlx/

ARCH		= ft mlx

LIBFT		= libft/libft.a
MLX			= mlx/libmlx.dylib

#sources=======================================================================

SRCS	= srcs/color/color.c \
		  srcs/color/color_mix.c \
		  srcs/hooks/hooks.c \
		  srcs/hooks/reset_settings.c \
		  srcs/image/bicubic.c \
		  srcs/image/mlx_img.c \
		  srcs/kd_tree/build.c \
		  srcs/kd_tree/build/bounding_volume.c \
		  srcs/kd_tree/build/cost.c \
		  srcs/kd_tree/build/split.c \
		  srcs/kd_tree/init.c \
		  srcs/kd_tree/print.c \
		  srcs/kd_tree/remove_tree.c \
		  srcs/object/init_object.c \
		  srcs/object/set_bounding_volume.c \
		  srcs/ray_tracer/shoot_a_ray.c \
		  srcs/run_mlx.c \
		  srcs/sort_memory.c \
		  srcs/vector/vector_condition.c \
		  srcs/vector/vector_constant.c \
		  srcs/vector/vector_operation.c \
		  srcs/vector/vector_scalar_operation.c \
		  srcs/vector/vector_transformation.c \
		  testfiles/test_kd_tree_building.c
		  #testfiles/test_bicubic_resizing.c
		  #srcs/main.c

OBJS	= $(SRCS:.c=.o)

#targets=======================================================================

TARGET_LIB		= $(LIBFT) $(MLX)
TARGET_LIBDIR	= $(LIBDIR)
TARGET_ARCH		= $(ARCH)
TARGET_OBJS		= $(OBJS)

#rules=========================================================================

.PHONY: all
all : $(TARGET_LIB)
	make $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(CC) -o $@ $(TARGET_OBJS) $(LDFLAGS)

$(LIBFT) :
	make -C libft

$(MLX) :
	make -C mlx
	cp mlx/libmlx.dylib .

#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(foreach include, $(INCLUDE), -I$(include))

.PHONY: oclean
oclean:
	rm -f $(OBJS)

.PHONY: clean
clean :
	rm -f $(OBJS)
	make fclean -C libft
	make fclean -C mlx

.PHONY: fclean
fclean :
	rm -f $(NAME)
	rm -f libmlx.dylib
	make clean

.PHONY: re
re :
	make fclean
	make all

.PHONY: bonus
bonus :
	make all
