VERMILION_RED=\033[1;31m

AZUR_BLUE=\033[1;34m

GOLD_COLOR=\033[38;5;220m

GREEN=\033[0;32m

RESET=\033[0m


FILES = main.c help_n_errors.c parse_av.c utils.c\
				philo.c

SRC=$(addprefix srcs/,$(FILES))

OBJECTS = $(addprefix build/,$(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = includes/

DEPS = includes/philo_bonus.h

NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJECTS) $(DEPS)
	@echo "$(AZUR_BLUE)Compiling $(NAME) ... $(RESET)"\ 
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GOLD_COLOR)Compilation Done. $(RESET)"

build/%.o:srcs/%.c $(DEPS)
	@mkdir -p build
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	@echo "$(VERMILION_RED)Cleaning ... $(RESET)"\ 
	@rm -rf build
	@echo "$(VERMILION_RED) Done. $(RESET)"\ 

fclean: clean
	@echo "$(VERMILION_RED)Deep cleaning ... $(RESET)"\ 
	@rm -rf $(NAME)
	@echo "$(VERMILION_RED) Done. $(RESET)"\ 

bonus: all

re: fclean all

.Phony : all clean fclean bonus re
