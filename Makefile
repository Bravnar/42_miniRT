NAME= miniRT

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
		srcs/init/init_new.c \
		srcs/parsing/read_rt_file.c \
		srcs/parsing/utils.c \
		srcs/matrices/basics/matrices_operations.c \
		srcs/matrices/basics/identity.c \
		srcs/matrices/basics/transpose.c \
		srcs/matrices/basics/determinant.c \
		srcs/matrices/basics/inverse.c \
		srcs/matrices/transformations/translation.c \
		srcs/matrices/transformations/scaling.c \
		srcs/matrices/transformations/rotation.c \
		srcs/matrices/transformations/shearing.c \
		srcs/raycasting/ray.c \
		srcs/raycasting/intersect.c \
		srcs/raycasting/hit.c \
		srcs/raycasting/ray_transform.c \
		srcs/shading/normal.c \
		srcs/shading/material.c \
		srcs/shading/reflect.c \
		srcs/shading/lighting.c \
		srcs/shading/lighting_utils.c \
		srcs/shapes/cube.c \
		srcs/shapes/cylinder.c \
		srcs/shapes/sphere.c \
		srcs/shapes/plane.c \
		srcs/utils/display.c \
		srcs/utils/sort_inter.c \
		srcs/parsing/ft_strtod.c \
		srcs/parsing/ft_strtoi.c \
		srcs/parsing/ambient/amb.c \
		srcs/parsing/camera/cam.c \
		srcs/parsing/resolution/res.c \
		srcs/error/ft_errorquit.c \
		srcs/parsing/counter.c \
		srcs/parsing/light/light_utils.c \
		srcs/parsing/light/light.c \
		srcs/parsing/objects/objects.c \
		srcs/parsing/objects/objects_utils.c \
		srcs/init/scene_getters.c \
		srcs/parsing/objects/objects_utils.c \
		srcs/world/world.c

CC= cc

CFLAGS= -Wall -Wextra -Werror -I$(INCLUDES)

LINUX_MINILIBX = -lXext -lX11 -lm

MINILIBX_DIR = minilibx-linux

LIBFT = 	lib
LIBFT_LIB = $(LIBFT)/my_lib.a

# SANITIZE= -g3 -fsanitize=address
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

.PHONY: all clean fclean re libft header

all: $(NAME)

header:
		@echo "$(CYAN) _______  __    __   __         .______        ___      .__   __.   _______  _______ .______          _______.";
		@echo "$(RED)|   ____||  |  |  | |  |        |   _  \      /   \     |  \ |  |  /  _____||   ____||   _  \        /       |";
		@echo "$(CYAN)|  |__   |  |__|  | |  |        |  |_)  |    /  ^  \    |   \|  | |  |  __  |  |__   |  |_)  |      |   (----\`";
		@echo "$(RED)|   __|  |   __   | |  |        |   _  <    /  /_\  \   |  . \`  | |  | |_ | |   __|  |      /        \   \    ";
		@echo "$(CYAN)|  |____ |  |  |  | |  \`----.   |  |_)  |  /  _____  \  |  |\   | |  |__| | |  |____ |  |\  \----.----)   |   ";
		@echo "$(RED)|_______||__|  |__| |_______|   |______/  /__/     \__\ |__| \__|  \______| |_______|| _| \`._____|_______/    $(RESET)";


$(NAME) : $(SRCS)
			@$(MAKE) header
			@echo "\n\nCompiling LIBFT: (loading bar - courtesy of rrouille)\n"
			@make -C $(LIBFT) all
			@echo "\n\nCompiling MINILIBX: (loading bar - courtesy of rrouille)\n"
			@make -C $(MINILIBX_DIR) all
			@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LIB) -L$(LIBFT) -L$(MINILIBX_DIR) -lmlx $(LINUX_MINILIBX) $(SANITIZE)
			@echo "$(YELLOW)\no------------------------------------o$(RESET)"
			@echo "$(GREEN)|           MINIRT_COMPILED          |$(RESET)"
			@echo "$(YELLOW)o------------------------------------o\n$(RESET)"

clean:
	@$(MAKE) header
	@echo "${RED}\nCleaning up...${RESET}"
	@rm -f $(NAME)
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
