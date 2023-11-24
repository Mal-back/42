
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:29:33 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 18:44:04 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rb(tdc_list **list_b, int f)
{
	if (!*list_b || !(*list_b)->next)
		return ;
	if (f)
		ft_putendl_fd("rb", 1);
	*list_b = (*list_b)->next;
	return ;
}
