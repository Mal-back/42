VERMILION_RED=\033[1;31m

AZUR_BLUE=\033[1;34m

GOLD_COLOR=\033[38;5;220m

GREEN=\033[0;32m

RESET=\033[0m

LB_DIR = lib

FILES = main.c ft_clean_exit.c

SRC=$(addprefix srcs/,$(FILES))

LIB_DIR = libft/

LIBFT = libft.a

OBJECTS = $(addprefix build/,$(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = includes/

DEPS = includes/pipex.h

NAME = pipex

all : dir libft $(NAME)

$(NAME) : $(OBJECTS) $(DEPS)
	@echo "$(AZUR_BLUE)Compiling $(NAME) ... $(RESET)"\ 
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LB_DIR)/$(LIBFT)
	@echo "$(GOLD_COLOR)Compilation Done. $(RESET)"

libft :
	@if [ ! -f "$(LB_DIR)/$(LIBFT)" ]; then \
		echo "$(GREEN)Compiling libft ... $(RESET)";\
		make -C$(LB_DIR)/$(LIB_DIR) > /dev/null;\
	fi

dir :
	@mkdir -p $(LB_DIR)

build/%.o:srcs/%.c $(DEPS)
	@mkdir -p build
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	@echo "$(VERMILION_RED)Cleaning ... $(RESET)"\ 
	@rm -rf build
	@make clean -C$(LB_DIR)/$(LIB_DIR) > /dev/null
	@echo "$(VERMILION_RED) Done. $(RESET)"\ 

fclean: clean
	@echo "$(VERMILION_RED)Deep cleaning ... $(RESET)"\ 
	@rm -rf $(NAME) $(LIBFT)
	@make fclean -C$(LB_DIR)/$(LIB_DIR) > /dev/null
	@echo "$(VERMILION_RED) Done. $(RESET)"\ 

bonus: all

re: fclean all

.Phony : all libft dir clean fclean bonus re
