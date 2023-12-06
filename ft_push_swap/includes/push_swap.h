/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:47:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 20:02:55 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_dclist
{
	struct s_dclist	*prev;
	long			data;
	struct s_dclist	*next;
}							t_dclist;

t_dclist	*ft_lst_dcnew(long data);
t_dclist	*ft_lst_dcclear(t_dclist **lst);
t_dclist	*ft_algo_init(t_dclist *list);
t_dclist	*ft_find_little(t_dclist **list_a);
t_dclist	*ft_find_big(t_dclist **list);
long		ft_find_median(t_dclist **list);
long		ft_find_median_b(t_dclist **list);
t_dclist	*ft_find_next_little(t_dclist *list_a, t_dclist **little);
void		ft_lst_copy(t_dclist **src, t_dclist **dest);
void		ft_sort_3(t_dclist **list_a);
void		ft_sort_4(t_dclist **list_a);
void		ft_sort_5(t_dclist **list_a);
int			ft_is_sorted(t_dclist *list);
void		ft_lstdcadd_front(t_dclist **list, t_dclist *new_node);
void		ft_quick_sort_init(t_dclist **list_a, int absolute_size_a);
void		ft_push_if_above_median(t_dclist **list_a, t_dclist **list_b,
				int median_of_three, int absolute_size);
void		ft_dcdel(t_dclist *node, t_dclist **list);
void		ft_push_if_below_median(t_dclist **list_a, t_dclist **list_b,
				int median_of_three, int absolute_size);
void		ft_quick_sort_a(t_dclist **list_a, int ultimate_size_a,
				int ultimate_size_b);
void		ft_quick_sort_b(t_dclist **list_b, int ultimate_size_a,
				int ultimate_size_b);
void		ft_manual_sort(t_dclist **list_a, int lst_size);
void		ft_update_lstdc(t_dclist **list);
void		ft_lstdcadd_back(t_dclist **lst, t_dclist *new_node);
int			parse_av(char *str, t_dclist **list);
int			ft_lst_dcsize(t_dclist *lst);
int			ft_find_median_of_three(t_dclist *list, int lst_size);
void		ft_merge_to_a(t_dclist **list_a, t_dclist **list_b);
void		ft_merge_to_b(t_dclist **list_a, t_dclist **list_b);
int			check_doublons(long nb, t_dclist *list);
long		ft_atol(char **str);
int			ft_isblank(int c);
int			ft_is_sign(char c);
void		ft_sa(t_dclist **list_a, int f);
void		ft_sb(t_dclist **list_b, int f);
void		ft_ss(t_dclist **list_a, t_dclist **list_b);
void		ft_pa(t_dclist **list_a, t_dclist **list_b);
void		ft_pb(t_dclist **list_b, t_dclist **list_a);
void		ft_pa(t_dclist **list_a, t_dclist **list_b);
void		ft_rb(t_dclist **list_b, int f);
void		ft_ra(t_dclist **list_a, int f);
void		ft_rr(t_dclist **list_a, t_dclist **list_b);
void		ft_rra(t_dclist **list_a, int f);
void		ft_rrb(t_dclist **list_b, int f);
void		ft_rrr(t_dclist **list_a, t_dclist **list_b);



int			need_to_swap(t_dclist **list);
void		bubble_sort_5(t_dclist **list_a);
void		ft_bubble_sort(t_dclist **list_a, t_dclist **list_b);
void		ft_bubble_sort_b(t_dclist **list_b, t_dclist **list_a);
int			need_to_push_back_tail(t_dclist **src, t_dclist **dest);
int			need_to_push_back_head(t_dclist **src, t_dclist **dest);
int			before_is_smaller(t_dclist **list);
int			after_is_bigger(t_dclist **list);


void		ft_merge_sort_init(t_dclist **list_a, int size_a);
void		ft_merge_sort_b(t_dclist **list_b, int size_a, int size_b);
void		ft_merge_sort_a(t_dclist **list_a, int size_a, int size_b);
void		ft_resolve_a(t_dclist **list_a, t_dclist **list_b,
				int size_a);
void		ft_resolve_b(t_dclist **list_a, t_dclist **list_b,
				int size_b);

void	ft_print_test(t_dclist *lst);


#endif
