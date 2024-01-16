FILES = check_doublons.c\
				ft_algo_init.c\
				ft_atoll.c	ft_isblank.c\
				ft_is_sign.c	ft_lstdcadd_back.c\
				ft_lstdc_clear.c	ft_lstdc_new.c\
				ft_lstdc_size.c	ft_pa.c\
				ft_pb.c	ft_ra.c\
				ft_rb.c	ft_rra.c\
				ft_rrb.c	ft_rr.c\
				ft_rrr.c	ft_sa.c\
				ft_sb.c	ft_ss.c\
				main.c	parse_av.c\
				ft_lstdcadd_front.c\
				ft_update_lstdc.c\
				ft_is_sorted.c ft_manual_sort.c\
				ft_find_little.c\
				ft_large_stack.c\
				ft_sort_3.c ft_sort_4.c\
				ft_sort_5.c\
				ft_find_next_little.c\
				ft_find_next_big.c\
				need_to_swap.c\
				ft_find_big.c\
				ft_is_reverse_sorted.c\
				ft_smart_push_back.c ft_cost_big_utils.c\
				push_cheapest.c ft_push_back_b.c\

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

SRC = $(addprefix srcs/,$(FILES))

CHECKER_OBJECTS = ${CHECKER_FILES:.c=.o}

OBJECTS = $(addprefix build/,${FILES:.c=.o})

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

build/%.o:srcs/%.c
	@mkdir -p build/
	$(CC) -I ${INCLUDES} -o $@ -c $<

clean :
	make clean -C ${SUBDIR}
	rm -f ${OBJECTS} ${CHECKER_OBJECTS}

fclean : clean
	make fclean -C ${SUBDIR}
	rm -f ${NAME} ${CHECKER_NAME}

re : fclean all

.PHONY : all clean fclean re checker
