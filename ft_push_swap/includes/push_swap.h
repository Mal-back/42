/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:47:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 19:05:58 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_dclist
{
	struct s_dclist	*prev;
	long			data;
	int				index;
	int				target;
	int				direction_a;
	int				rotate_cost_a;
	int				direction_b;
	int				rotate_cost_b;
	int				final_cost;
	int				cheapest;
	struct s_dclist	*next;
}							t_dclist;

typedef struct s_data_info
{
	int	value;
	int	min;
	int	max;
	int	cost_to_rotate_b;
	int	direction_b;
	int	cost_to_rotate_a;
	int	direction_a;
	int	final_cost;
}							t_data_info;

typedef struct s_sort_info_a
{
	long	little;
	long	next_little;
	int		push_little_is_mandatory;
}							t_sort_info_a;

typedef struct s_sort_info_b
{
	long	big;
	long	next_big;
	int		push_big_is_mandatory;
}							t_sort_info_b;

t_dclist	*ft_lst_dcnew(long data);
t_dclist	*ft_lst_dcclear(t_dclist **lst);
t_dclist	*ft_algo_init(t_dclist *list);
long		ft_find_little(t_dclist **list_a);
long		ft_find_big(t_dclist **list);
long		ft_find_next_big(t_dclist **list, long big);
long		ft_find_median(t_dclist **list);
long		ft_find_median_b(t_dclist **list);
long		ft_find_next_little(t_dclist *list_a, long little);
void		ft_lst_copy(t_dclist **src, t_dclist **dest);
void		ft_sort_3(t_dclist **list_a);
void		ft_sort_4(t_dclist **list_a);
void		ft_sort_5(t_dclist **list_a);
int			ft_is_sorted(t_dclist *list);
int			ft_is_reverse_sorted(t_dclist *list);
void		ft_lstdcadd_front(t_dclist **list, t_dclist *new_node);
void		ft_quick_sort_init(t_dclist **list_a, int absolute_size_a);
void		ft_push_if_above_median(t_dclist **list_a, t_dclist **list_b,
				int median_of_three, int absolute_size);
void		ft_dcdel(long node, t_dclist **list);
void		ft_push_init(t_dclist **list_a, t_dclist **list_b,
				int limit, int upper_limit);
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



void		identify_cheapest(t_dclist **list_a, t_dclist **list_b,
				t_dclist **cheapest_node);
void		smart_push_back(t_dclist **list_a, t_dclist **list_b);
void		resolve_direction_b(t_dclist **list_b, t_dclist **looked_position);
void		resolve_direction_a(int go_cost, int go_back_cost,
				t_data_info *data_info);
void		resolve_cost(t_dclist **looked_position);
void		ft_cost_to_go_b(t_dclist **list_b, int number,
				int *go_cost, int *go_back_cost);
int			ft_cost_to_go_a(t_dclist **list_a, t_dclist **looked_position);
void		combine_rotate(t_dclist **list_a, t_dclist **list_b,
				t_dclist **cheapest_node);
int			is_in_range(t_dclist **list_a, t_data_info *data_info);
int			a_is_to_good_place(t_dclist **list_a, t_data_info *data_info);
void		push_cheapest(t_dclist **list_a, t_dclist **list_b,
				t_dclist **cheapest_node);
void		ft_push_back_b(t_dclist **list_a, t_dclist **list_b);
void		ft_indentify_cost(t_dclist **list_a, int data,
				int	*go_cost, int	*go_back_cost);

int			need_to_swap(t_dclist **list);
void		bubble_sort_5(t_dclist **list_a);
void		ft_bubble_sort(t_dclist **list_a, t_dclist **list_b);
void		ft_bubble_sort_b(t_dclist **list_b, t_dclist **list_a);
int			need_to_push_back_tail(t_dclist **src, t_dclist **dest);
int			need_to_push_back_head(t_dclist **src, t_dclist **dest);
int			before_is_smaller(t_dclist **list);
int			after_is_bigger(t_dclist **list);
void		final_sort_a(t_dclist **list_a, t_dclist **list_b);
void		init_sort_info_a(t_dclist **list_a, t_sort_info_a *sort_info,
				int push_little_is_mandatory);
void		sort_up_a(t_dclist **list_a, t_dclist **list_b,
				t_dclist **tail_a, t_sort_info_a *sort_info);
void		sort_down_a(t_dclist **list_a, t_dclist **list_b,
				t_dclist **head_a, t_sort_info_a *sort_info);
void		final_sort_b(t_dclist **list_b, t_dclist **list_a);
void		init_sort_info_b(t_dclist **list_b, t_sort_info_b *sort_info,
				int need_to_push_big);
void		sort_down_b(t_dclist **list_b, t_dclist **list_a,
				t_dclist **head_b, t_sort_info_b *sort_info);
void		sort_up_b(t_dclist **list_b, t_dclist **list_a,
				t_dclist **tail_b, t_sort_info_b *sort_info);


void		ft_merge_sort_init(t_dclist **list_a, int size_a);
void		ft_merge_sort_b(t_dclist **list_b, int size_a, int size_b);
void		ft_merge_sort_a(t_dclist **list_a, int size_a, int size_b);
void		ft_resolve_a(t_dclist **list_a, t_dclist **list_b,
				int size_a);
void		ft_resolve_b(t_dclist **list_a, t_dclist **list_b,
				int size_b);

void	ft_print_test(t_dclist *lst);


#endif
