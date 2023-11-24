/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:47:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 19:04:49 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct sdc_list
{
	struct sdc_list	*prev;
	void		*data;
	struct sdc_list	*next;
}							tdc_list;

tdc_list	*ft_lstdc_new(void *data);
tdc_list	*ft_lstdc_clear(tdc_list **lst);
tdc_list	*ft_algo_init(tdc_list *list);
int				ft_lstdc_size(tdc_list *lst);
int				check_doublons(long nb, tdc_list *list);
void			ft_lstdcadd_back(tdc_list **lst, tdc_list *new_node);
int				parse_av(char *str, tdc_list **list);
long			ft_atol(char **str);
int				ft_isblank(int c);
int				ft_is_sign(char c);
void			ft_sa(tdc_list **list_a, int f);
void			ft_sb(tdc_list **list_b, int f);
void			ft_ss(tdc_list **list_a, tdc_list **list_b);
void			ft_pa(tdc_list **list_a, tdc_list **list_b);
void			ft_pb(tdc_list **list_b, tdc_list **list_a);
void			ft_pa(tdc_list **list_a, tdc_list **list_b);
void			ft_rb(tdc_list **list_b, int f);
void			ft_ra(tdc_list **list_a, int f);
void			ft_rr(tdc_list **list_a, tdc_list **list_b);
void			ft_rra(tdc_list **list_a, int f);
void			ft_rrb(tdc_list **list_b, int f);
void			ft_rrr(tdc_list **list_a, tdc_list **list_b);

#endif

