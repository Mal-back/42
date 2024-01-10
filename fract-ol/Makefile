VERMILION_RED=\033[1;31m

AZUR_BLUE=\033[1;34m

GOLD_COLOR=\033[38;5;220m

GREEN=\033[0;32m

RESET=\033[0m

MLX_DIR = mini_libx

MLX_LIB = libmlx.a

MLX_HEADER = mlx.h

LB_DIR = lib

FILES = compute_bs.c  compute_Julia.c  compute_mndelbrot.c  compute_utils.c\
				drawing_utils.c  event_handling.c  ft_av_utils.c  ft_color.c\
				ft_display_command.c  init_buttons.c  init_window.c\
				kill_functions.c  main.c

SRC=$(addprefix srcs/,$(FILES))

LIB_DIR = libft/

LIBFT = libft.a

OBJECTS = $(addprefix build/,$(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror -march=native -O3 -fast -flto -lXext -lX11 -lm -lz

INCLUDES = includes/

DEPS = includes/fract_ol.h includes/mlx.h includes/libft.h

NAME = fractol

all : dir mlx libft $(NAME)

$(NAME) : $(OBJECTS) $(DEPS)
	@echo "$(AZUR_BLUE)Compiling fractol ... $(RESET)"\ 
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LB_DIR)/$(LIBFT) $(LB_DIR)/$(MLX_LIB)
	@echo "$(GOLD_COLOR)Compilation Done. $(RESET)"

mlx_repo :
	@if [ ! -d "$(LB_DIR)/$(MLX_DIR)" ]; then \
		echo "$(VERMILION_RED)You didn't have mlx lol; Cloning it.$(RESET)"; \
		cd lib; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) > /dev/null 2>&1; \
		cd ..; \
	fi

libft :
	@if [ ! -f "$(LB_DIR)/$(LIBFT)" ]; then \
		echo "$(GREEN)Compiling libft ... $(RESET)";\
		make -C$(LB_DIR)/$(LIB_DIR) > /dev/null;\
	fi

mlx : mlx_repo
	@if [ ! -f "$(LB_DIR)/$(MLX_LIB)" ]; then \
		echo "$(GREEN)Compiling MLX... $(RESET)"; \
		make -C$(LB_DIR)/$(MLX_DIR) > /dev/null 2>&1; \
		mv $(LB_DIR)/$(MLX_DIR)/$(MLX_LIB) $(LB_DIR); \
		mv $(LB_DIR)/$(MLX_DIR)/$(MLX_HEADER) $(INCLUDES); \
	fi

dir :
	@mkdir -p $(LB_DIR)

build/%.o:srcs/%.c $(DEPS)
	@mkdir -p build
	@$(CC) -I$(INCLUDES) -o $@ -c $<

clean:
	@echo "$(VERMILION_RED)Cleaning ... $(RESET)"\ 
	@rm -rf build
	@make clean -C$(LB_DIR)/$(LIB_DIR) > /dev/null
	@echo "$(VERMILION_RED) Done. $(RESET)"\ 

fclean: clean
	@echo "$(VERMILION_RED)Deep cleaning ... $(RESET)"\ 
	@rm -rf $(NAME) $(LB_DIR)/$(MLX_LIB) $(LB_DIR)/$(MLX_DIR) $(LIBFT)
	@rm -rf $(INCLUDES)/$(MLX_HEADER)
	@make fclean -C$(LB_DIR)/$(LIB_DIR) > /dev/null
	@echo "$(VERMILION_RED) Done. $(RESET)"\ 

bonus: $(NAME)

re: fclean all
