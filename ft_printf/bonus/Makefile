FILES = srcs/driver.c srcs/ft_handler1.c srcs/ft_handler2.c srcs/output_f.c

INCLUDES = includes/

SUBDIR = libft/

OBJECTS = ${FILES:.c=.o}

BONUS_OBJ = ${BONUS:.c=.o}

CC = cc -Wall -Wextra -Werror

NAME = libftprintf.a

all : ${SUBDIR}

${SUBDIR} : ${NAME}
	make -C ${SUBDIR}

${NAME} : ${OBJECTS}
	ar rcs $@ ${OBJECTS}

%.o:%.c
	${CC} -c $< -o $@ -I ${INCLUDES}

clean :
	make clean -C ${SUBDIR}
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean : 		clean
	make fclean -C ${SUBDIR}
	rm -f ${NAME} ${BONUS_OBJ}

re : fclean all

bonus : ${BONUS_OBJ} ${OBJECTS} $(NAME)
	ar rcs ${NAME} ${BONUS_OBJ} ${OBJECTS}

.PHONY : all re fclean clean bonus
