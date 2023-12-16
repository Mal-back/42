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
				srcs/ft_is_sorted.c srcs/ft_manual_sort.c\
				srcs/ft_find_little.c\
				srcs/ft_large_stack.c\
				srcs/ft_sort_3.c srcs/ft_sort_4.c\
				srcs/ft_sort_5.c\
				srcs/ft_find_next_little.c\
				srcs/ft_find_next_big.c\
				srcs/need_to_swap.c\
				srcs/ft_find_big.c\
				srcs/ft_is_reverse_sorted.c\
				srcs/ft_smart_push_back.c srcs/ft_cost_big_utils.c\
				srcs/push_cheapest.c srcs/ft_push_back_b.c\

CHECKER_FILES =		srcs/check_doublons.c bonus_srcs/free_and_exit.c\
									bonus_srcs/free_tab.c bonus_srcs/ft_apply_instructions.c\
									srcs/ft_atoll.c bonus_srcs/ft_check_instructions.c\
									srcs/ft_is_sign.c\
									srcs/ft_is_sorted.c srcs/ft_lstdcadd_back.c\
									srcs/ft_lstdcadd_front.c srcs/ft_lstdc_clear.c\
									srcs/ft_lstdc_new.c srcs/ft_lstdc_size.c\
									bonus_srcs/ft_pa.c bonus_srcs/ft_parse_instructions.c\
									bonus_srcs/ft_pb.c srcs/ft_ra.c\
									srcs/ft_rb.c srcs/ft_rra.c\
									srcs/ft_rrb.c bonus_srcs/ft_rr.c\
									bonus_srcs/ft_rrr.c srcs/ft_sa.c\
									srcs/ft_sb.c bonus_srcs/ft_ss.c\
									bonus_srcs/main.c srcs/parse_av.c\
									srcs/ft_update_lstdc.c\

CHECKER_OBJECTS = ${CHECKER_FILES:.c=.o} 

OBJECTS = ${FILES:.c=.o}

SUBDIR = libft/

CC = cc -Wall -Wextra -Werror -g3

INCLUDES = includes/

NAME = push_swap

CHECKER_NAME = checker_bonus

all : ${NAME}

checker : ${CHECKER_NAME}

${NAME} : ${OBJECTS} 
	make -C ${SUBDIR}
	${CC} ${OBJECTS} -o ${NAME} -L. -lft

${CHECKER_NAME} : ${CHECKER_OBJECTS}
	make -C ${SUBDIR}
	${CC} ${CHECKER_OBJECTS} -o ${CHECKER_NAME} -L. -lft

%.o:%.c
	$(CC) -I ${INCLUDES} -o $@ -c $<

clean :
	make clean -C ${SUBDIR}
	rm -f ${OBJECTS} ${CHECKER_OBJECTS}

fclean : clean
	make fclean -C ${SUBDIR}
	rm -f ${NAME} ${CHECKER_NAME}

re : fclean all

.PHONY : all clean fclean re checker
