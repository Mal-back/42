FILES = srcs/check_doublons.c\
				srcs/ft_algo_init.c\
				srcs/ft_atoll.c	srcs/ft_isblank.c\
				srcs/ft_is_sign.c	srcs/ft_lstdcadd_back.c\
				srcs/ft_lstdc_clear.c	srcs/ft_lstdc_new.c\
				srcs/ft_lstdc_size.c	srcs/ft_pa.c\
				srcs/ft_pb.c	srcs/ft_ra.c\
				srcs/ft_rb.c	srcs/ft_rra.c\
				srcs/ft_rrb.c	srcs/ft_rr.c\
				srcs/ft_rrr.c	srcs/ft_sa.c\
				srcs/ft_sb.c	srcs/ft_ss.c\
				srcs/main.c	srcs/parse_av.c\
				srcs/ft_lstdcadd_front.c\
				srcs/ft_update_lstdc.c\

OBJECTS = ${FILES:.c=.o}

SUBDIR = libft/ 

CC = cc -Wall -Wextra -Werror -g3

INCLUDES = includes/

NAME = push_swap

all : ${NAME}

${NAME} : ${OBJECTS} 
	make -C ${SUBDIR}
	${CC} ${OBJECTS} -o ${NAME} -L. -lft

%.o:%.c
	$(CC) -I ${INCLUDES} -o $@ -c $<

clean :
	make clean -C ${SUBDIR}
	rm -f ${OBJECTS} 
 
fclean : clean
	make fclean -C ${SUBDIR}
	rm -f ${NAME}

re : fclean all

.PHONY : all ${NAME} clean fclean re
