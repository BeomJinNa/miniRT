#parameters====================================================================

CC			= cc

COMMONFLAGS	=

CFLAGS		= $(COMMONFLAGS) -Wall -Wextra -Werror

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

SRCS	= srcs/main.c \
		  srcs/color/color.c \
		  srcs/color/color_mix.c \
		  srcs/hooks/hooks.c \
		  srcs/hooks/reset_settings.c \
		  srcs/image/mlx_img.c \
		  srcs/kd-tree/build.c \
		  srcs/kd-tree/build/bounding_volume.c \
		  srcs/kd-tree/build/cost.c \
		  srcs/kd-tree/build/split.c \
		  srcs/kd-tree/init.c \
		  srcs/kd-tree/remove_tree.c \
		  srcs/run_mlx.c \
		  srcs/sort_memory.c \
		  srcs/vector/vector_operation.c

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
	make clean

.PHONY: re
re :
	make fclean
	make all

.PHONY: bonus
bonus :
	make all
