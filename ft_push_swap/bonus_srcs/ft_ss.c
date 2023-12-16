/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:47:05 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:21:17 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_dclist **list_a, t_dclist **list_b)
{
	if (!*list_a || !*list_b)
		return ;
	if ((*list_a)->next == NULL && (*list_b)->next == NULL)
		return ;
	ft_sa(list_a, 0);
	ft_sb(list_b, 0);
}
