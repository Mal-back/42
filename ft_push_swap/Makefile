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
				srcs/ft_find_median_of_three.c\
				srcs/ft_push_if_above_median.c\
				srcs/ft_push_if_below_median.c\
				srcs/ft_merge_to_a.c\
				srcs/ft_quick_sort_a.c\
				srcs/ft_quick_sort_init.c\
				srcs/ft_quick_sort_b.c\
				srcs/ft_merge_to_b.c\
				srcs/ft_sort_3.c srcs/ft_sort_4.c\
				srcs/ft_sort_5.c\
				srcs/ft_find_next_little.c\
				srcs/ft_merge_sort_init.c\
				srcs/ft_merge_sort_a.c srcs/ft_resolve_a.c\
				srcs/ft_merge_sort_b.c srcs/ft_resolve_b.c\
				srcs/need_to_swap.c srcs/ft_bubble_sort.c\
				srcs/bubble_sort_utils.c srcs/ft_find_median.c\
				srcs/ft_lst_cpy.c srcs/ft_find_big.c\
				srcs/ft_dcdel.c srcs/ft_find_median_b.c\
				srcs/ft_bubble_sort_b.c srcs/ft_final_sort_a_2.c\
				srcs/ft_final_sort_a.c srcs/ft_find_next_big.c\
				srcs/ft_final_sort_b.c srcs/ft_final_sort_b_2.c\
				srcs/ft_is_reverse_sorted.c\

CHECKER_FILES =		bonus_srcs/check_doublons.c bonus_srcs/free_and_exit.c\
									bonus_srcs/free_tab.c bonus_srcs/ft_apply_instructions.c\
									bonus_srcs/ft_atoll.c bonus_srcs/ft_check_instructions.c\
									bonus_srcs/ft_isblank.c bonus_srcs/ft_is_sign.c\
									bonus_srcs/ft_is_sorted.c bonus_srcs/ft_lstdcadd_back.c\
									bonus_srcs/ft_lstdcadd_front.c bonus_srcs/ft_lstdc_clear.c\
									bonus_srcs/ft_lstdc_new.c bonus_srcs/ft_lstdc_size.c\
									bonus_srcs/ft_pa.c bonus_srcs/ft_parse_instructions.c\
									bonus_srcs/ft_pb.c bonus_srcs/ft_ra.c\
									bonus_srcs/ft_rb.c bonus_srcs/ft_rra.c\
									bonus_srcs/ft_rrb.c bonus_srcs/ft_rr.c\
									bonus_srcs/ft_rrr.c bonus_srcs/ft_sa.c\
									bonus_srcs/ft_sb.c bonus_srcs/ft_ss.c\
									bonus_srcs/main.c bonus_srcs/parse_av.c\
									bonus_srcs/ft_update_lstdc.c\

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
