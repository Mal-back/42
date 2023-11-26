/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:47:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/26 20:29:07 by vlevy            ###   ########.fr       */
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
void		ft_lstdcadd_front(t_dclist **list, t_dclist *new_node);
void		ft_update_lstdc(t_dclist **list);
void		ft_lstdcadd_back(t_dclist **lst, t_dclist *new_node);
int			parse_av(char *str, t_dclist **list);
int			ft_lst_dcsize(t_dclist *lst);
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

#endif
