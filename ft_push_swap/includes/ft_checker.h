/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:33:59 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 20:46:01 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H

# define FT_CHECKER_H

# include "libft.h"
# include <limits.h>

typedef struct s_dclist
{
	struct s_dclist	*prev;
	int				data;
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

void		ft_parse_instructions(t_dclist **lst);
int			ft_check_instructions(char **instructions_tab, char *str);
void		ft_apply_instructions(t_dclist **list_a,
				t_dclist **list_b, int instructions);
void		free_and_exit(t_dclist **list_a, t_dclist **list_b,
				char ***tab, char *str);
void		free_tab(char ***tab);
t_dclist	*ft_lst_dcnew(long data);
t_dclist	*ft_lst_dcclear(t_dclist **lst);
int			ft_lst_dcsize(t_dclist *lst);
int			ft_is_sorted(t_dclist *list);
void		ft_lstdcadd_front(t_dclist **list, t_dclist *new_node);
void		ft_update_lstdc(t_dclist **list);
void		ft_lstdcadd_back(t_dclist **lst, t_dclist *new_node);
int			parse_av(char *str, t_dclist **list);
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
#endif // !FT_CHECKER_H
