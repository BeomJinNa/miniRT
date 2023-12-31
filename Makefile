#parameters====================================================================

CC			= cc

COMMONFLAGS	=

CFLAGS		= $(COMMONFLAGS) -Wall -Wextra -Werror -O2

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
MLX			= libmlx.dylib

#sources=======================================================================

SRCS	= srcs/color/color.c \
		  srcs/color/color_mix.c \
		  srcs/draw_image.c \
		  srcs/free.c \
		  srcs/hooks/camera/exposure.c \
		  srcs/hooks/camera/fov.c \
		  srcs/hooks/camera/move.c \
		  srcs/hooks/camera/move2.c \
		  srcs/hooks/camera/rotate.c \
		  srcs/hooks/hooks.c \
		  srcs/hooks/reset_settings.c \
		  srcs/image/bicubic.c \
		  srcs/image/convert.c \
		  srcs/image/mlx_img.c \
		  srcs/kd_tree/build.c \
		  srcs/kd_tree/build/bounding_volume.c \
		  srcs/kd_tree/build/cost.c \
		  srcs/kd_tree/build/split.c \
		  srcs/kd_tree/init.c \
		  srcs/kd_tree/print.c \
		  srcs/kd_tree/remove_tree.c \
		  srcs/kd_tree/traverse_tree.c \
		  srcs/object/init_object.c \
		  srcs/object/list.c \
		  srcs/object/print_object.c \
		  srcs/object/search_bounding_volume.c \
		  srcs/object/set_bounding_volume.c \
		  srcs/parse/converter/convert_additional_params.c \
		  srcs/parse/converter/convert_line_to_ambient_light.c \
		  srcs/parse/converter/convert_line_to_camera.c \
		  srcs/parse/converter/convert_line_to_cylinder.c \
		  srcs/parse/converter/convert_line_to_light.c \
		  srcs/parse/converter/convert_line_to_obj.c \
		  srcs/parse/converter/convert_line_to_plane.c \
		  srcs/parse/converter/convert_line_to_sphere.c \
		  srcs/parse/converter/rgb_to_ratio.c \
		  srcs/parse/check_acl_unique.c \
		  srcs/parse/parse.c \
		  srcs/parse/parse_error.c \
		  srcs/parse/parse_utils/parse_degree.c \
		  srcs/parse/parse_utils/parse_normalized_vector.c \
		  srcs/parse/parse_utils/parse_ratio.c \
		  srcs/parse/parse_utils/parse_real_number.c \
		  srcs/parse/parse_utils/parse_rgb.c \
		  srcs/parse/parse_utils/parse_unsigned_number.c \
		  srcs/parse/parse_utils/parse_vector.c \
		  srcs/parse/utils/lst_utils.c \
		  srcs/parse/utils/ptr_utils.c \
		  srcs/parse/utils/str_utils.c \
		  srcs/print.c \
		  srcs/ray_tracer/compute_lighting_from_spotlights.c \
		  srcs/ray_tracer/compute_scattering_lights.c \
		  srcs/ray_tracer/get_closest_intersection.c \
		  srcs/ray_tracer/get_intersection.c \
		  srcs/ray_tracer/get_intersection/cylinder.c \
		  srcs/ray_tracer/get_intersection/cylinder_utils.c \
		  srcs/ray_tracer/get_intersection/plane.c \
		  srcs/ray_tracer/get_intersection/sphere.c \
		  srcs/ray_tracer/print_cam_info.c \
		  srcs/ray_tracer/ray_condition.c \
		  srcs/ray_tracer/ray_operations.c \
		  srcs/ray_tracer/ray_transformation.c \
		  srcs/ray_tracer/re_render.c \
		  srcs/ray_tracer/render.c \
		  srcs/ray_tracer/set_ray.c \
		  srcs/ray_tracer/shoot_a_ray.c \
		  srcs/run_mlx.c \
		  srcs/sort_memory.c \
		  srcs/vector/matrix_operation.c \
		  srcs/vector/vector_condition.c \
		  srcs/vector/vector_constant.c \
		  srcs/vector/vector_create.c \
		  srcs/vector/vector_cutoff.c \
		  srcs/vector/vector_elementwise_operation.c \
		  srcs/vector/vector_operation.c \
		  srcs/vector/vector_scalar_operation.c \
		  srcs/vector/vector_transformation.c \
		  srcs/main.c

OBJS	= $(SRCS:.c=.o)

#targets=======================================================================

TARGET_LIB		= $(LIBFT) $(MLX)
TARGET_LIBDIR	= $(LIBDIR)
TARGET_ARCH		= $(ARCH)
TARGET_OBJS		= $(OBJS)

ifdef BONUS
	COMPILE = $(CC) $(CFLAGS) -c $< -o $@ $(foreach include, $(INCLUDE), -I$(include)) -D M_BONUS=1
else
	COMPILE = $(CC) $(CFLAGS) -c $< -o $@ $(foreach include, $(INCLUDE), -I$(include))
endif

#rules=========================================================================

.PHONY: all
all : $(TARGET_LIB)
	make $(NAME)

.PHONY: bonus
bonus : $(TARGET_LIB)
	make BONUS=0 $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(CC) -o $@ $(TARGET_OBJS) $(LDFLAGS)

$(LIBFT) :
	make -C libft

$(MLX) :
	make -C mlx
	cp mlx/libmlx.dylib .

#const options=================================================================

%.o : %.c
	$(COMPILE)

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

.PHONY: bore
bore :
	make oclean
	make bonus

.PHONY: ore
ore :
	make oclean
	make all

.PHONY: re
re :
	make fclean
	make all

.PHONY: norm
norm :
	norminette includes/ $(SRCS)
