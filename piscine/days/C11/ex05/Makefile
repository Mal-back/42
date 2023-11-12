FILES = srcs/main.c srcs/ft_pars_and_print.c srcs/ft_op.c 

OBJECT = ${FILES:.c=.o}

CC = cc -Wall -Wextra -Werror
NAME = do-op

HEADER = includes/

all : ${NAME}

${NAME} : ${OBJECT}
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -I$(HEADER) -c $< -o $@	

clean :
	rm -f ${OBJECT}

fclean : clean
	rm -f ${NAME}

re : fclean all
