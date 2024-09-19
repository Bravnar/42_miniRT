NAME= miniRT

NAME_BONUS= miniRT_bonus

MAKEFLAGS= --no-print-directory

INCLUDES = includes

SRCS= 	srcs/main.c \
		srcs/mlx_utils.c \
		srcs/event_handler.c \
		srcs/tuples/tuple_create.c \
		srcs/tuples/tuple_operations.c \
		srcs/tuples/vector_info.c \
		srcs/tuples/vector_operations.c \
		srcs/tuples/environment.c \
		srcs/tuples/projectile.c \
		srcs/tuples/tick.c \
		srcs/floats/float_compare.c \
		srcs/colors/colors_init.c \
		srcs/colors/colors_operations.c \
		srcs/colors/basic_colors.c \
		srcs/colors/patterns/pattern.c \
		srcs/colors/patterns/plain.c \
		srcs/colors/patterns/stripe.c \
		srcs/colors/patterns/gradient.c \
		srcs/colors/patterns/bump.c \
		srcs/init/init_new.c \
		srcs/matrices/basics/matrices_operations.c \
		srcs/matrices/basics/identity.c \
		srcs/matrices/basics/transpose.c \
		srcs/matrices/basics/determinant.c \
		srcs/matrices/basics/inverse.c \
		srcs/matrices/transformations/translation.c \
		srcs/matrices/transformations/scaling.c \
		srcs/matrices/transformations/rotation.c \
		srcs/matrices/transformations/rotate_pattern.c \
		srcs/matrices/transformations/shearing.c \
		srcs/raycasting/ray.c \
		srcs/raycasting/intersect.c \
		srcs/raycasting/hit.c \
		srcs/raycasting/ray_transform.c \
		srcs/raycasting/intersect_utils.c \
		srcs/raycasting/intersect_linked.c \
		srcs/shading/normal.c \
		srcs/shading/material.c \
		srcs/shading/reflect.c \
		srcs/shading/lighting.c \
		srcs/shading/lighting_utils.c \
		srcs/shapes/cube/cube.c \
		srcs/shapes/cube/cube_utils.c \
		srcs/shapes/cylinder/cylinder.c \
		srcs/shapes/cylinder/cylinder_utils.c \
		srcs/shapes/cylinder/cylinder_calculations.c \
		srcs/shapes/sphere/sphere.c \
		srcs/shapes/sphere/sphere_utils.c \
		srcs/shapes/plane/plane.c \
		srcs/shapes/plane/plane_utils.c \
		srcs/utils/display.c \
		srcs/utils/display_2.c \
		srcs/utils/memory.c \
		srcs/error/ft_errorquit.c \
		srcs/init/scene_getters.c \
		srcs/init/init_utils.c \
		srcs/world/world.c \
		srcs/shadows/is_shadowed.c \
		srcs/refraction/reflection.c \
		srcs/refraction/refraction.c \
		srcs/test/equals.c \
		srcs/test/lighting_test.c \
		srcs/test/ray_test.c \
		srcs/test/hit_test.c \
		srcs/test/patterns_test.c \
		srcs/test/test_main.c \
		srcs/world/view.c \
		srcs/scene_render.c \
		srcs/world/view_utils.c \
		srcs/parsing/converters/ft_rt_atoi.c \
		srcs/parsing/converters/ft_strtod.c \
		srcs/parsing/converters/ft_strtoi.c \
		srcs/parsing/fetching/fetching_amb.c \
		srcs/parsing/fetching/fetching_cam.c \
		srcs/parsing/fetching/fetching_lights_utils.c \
		srcs/parsing/fetching/fetching_lights.c \
		srcs/parsing/fetching/fetching_objs.c \
		srcs/parsing/fetching/fetching_res.c \
		srcs/parsing/fetching/fetching_utils.c \
		srcs/parsing/file_handle/parsing_counter.c \
		srcs/parsing/file_handle/parsing_main.c \
		srcs/parsing/file_handle/parsing_map_maker.c \
		srcs/parsing/file_handle/parsing_params.c \
		srcs/parsing/file_handle/parsing_prints.c \
		srcs/parsing/file_handle/parsing_read_file.c \
		srcs/parsing/file_handle/parsing_utils_llists.c \
		srcs/parsing/file_handle/parsing_utils.c \
		srcs/parsing/initialization/main_init.c \
		srcs/parsing/bonus/parsing_counter_bonus.c \
		srcs/world/multiple_lights.c \

CC= cc

CFLAGS= -Wall -Wextra -Werror -I$(INCLUDES)
CFLAGS_BONUS = -Wall -Wextra -Werror -I$(INCLUDES) -D RT_BONUS=1

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MINILIBX_DIR = minilibx-linux
	MINILIBX_FLAGS = -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
	MINILIBX_DIR = minilibx_macos
	MINILIBX_FLAGS = -lm -framework OpenGL -framework AppKit
endif

LIBFT = 	lib
LIBFT_LIB = $(LIBFT)/my_lib.a

#SANITIZE= -g3 -fsanitize=address
SANITIZE= -g

# Color Variables
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
RESET=\033[0m

.PHONY: all clean fclean re libft header re

all: $(NAME)

bonus: $(NAME_BONUS)

header:
		@echo "$(CYAN) _______  __    __   __         .______        ___      .__   __.   _______  _______ .______          _______.";
		@echo "$(RED)|   ____||  |  |  | |  |        |   _  \      /   \     |  \ |  |  /  _____||   ____||   _  \        /       |";
		@echo "$(CYAN)|  |__   |  |__|  | |  |        |  |_)  |    /  ^  \    |   \|  | |  |  __  |  |__   |  |_)  |      |   (----\`";
		@echo "$(RED)|   __|  |   __   | |  |        |   _  <    /  /_\  \   |  . \`  | |  | |_ | |   __|  |      /        \   \    ";
		@echo "$(CYAN)|  |____ |  |  |  | |  \`----.   |  |_)  |  /  _____  \  |  |\   | |  |__| | |  |____ |  |\  \----.----)   |   ";
		@echo "$(RED)|_______||__|  |__| |_______|   |______/  /__/     \__\ |__| \__|  \______| |_______|| _| \`._____|_______/    $(RESET)";


$(NAME) : $(SRCS)
			@rm -f $(NAME_BONUS)
			@$(MAKE) header
			@echo "\n\nCompiling LIBFT: (loading bar - courtesy of rrouille)\n"
			@make -C $(LIBFT) all
			@echo "\n\nCompiling MINILIBX: (loading bar - courtesy of rrouille)\n"
			@make -C $(MINILIBX_DIR) all
			@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LIB) -L$(LIBFT) -L$(MINILIBX_DIR) -lmlx $(MINILIBX_FLAGS) $(SANITIZE)
			@echo "$(YELLOW)\no------------------------------------o$(RESET)"
			@echo "$(GREEN)|           MINIRT_COMPILED          |$(RESET)"
			@echo "$(YELLOW)o------------------------------------o\n$(RESET)"

$(NAME_BONUS) : $(SRCS)
			@rm -f $(NAME)
			@$(MAKE) header
			@echo "$(MAGENTA)\nWITH BONUS$(RESET)"
			@echo "\n\nCompiling LIBFT: (loading bar - courtesy of rrouille)\n"
			@make -C $(LIBFT) all
			@echo "\n\nCompiling MINILIBX: (loading bar - courtesy of rrouille)\n"
			@make -C $(MINILIBX_DIR) all
			@$(CC) $(CFLAGS_BONUS) -o $@ $^ $(LIBFT_LIB) -L$(LIBFT) -L$(MINILIBX_DIR) -lmlx $(MINILIBX_FLAGS) $(SANITIZE)
			@echo "$(YELLOW)\no------------------------------------o$(RESET)"
			@echo "$(GREEN)|           MINIRT_COMPILED          |$(RESET)"
			@echo "$(YELLOW)o------------------------------------o\n$(RESET)"
clean:
	@echo "${RED}\nCleaning up...${RESET}"
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(MINILIBX_DIR) clean
	@echo "${GREEN}Cleanup done.${RESET}"

fclean: 	clean
		@make -C $(LIBFT) fclean
		@rm -f $(NAME)
		@rm -rf objs
		@echo "$(YELLOW)\no------------------------------------o$(RESET)"
		@echo "$(RED)|           MINIRT_CLEARED           |$(RESET)"
		@echo "$(YELLOW)o------------------------------------o\n$(RESET)"

re: 			fclean all
