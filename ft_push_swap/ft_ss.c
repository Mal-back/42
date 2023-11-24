/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:47:05 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 17:52:36 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ss(tdc_list **list_a, tdc_list **list_b)
{
	if (!*list_a || !*list_b)
		return ;
	if ((*list_a)->next == NULL && (*list_b)->next == NULL)
		return ;
	ft_putendl_fd("ss", 1);
	ft_sa(list_a, 0);
	ft_sb(list_b, 0);
}
