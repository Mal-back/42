/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:35:10 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 18:32:15 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge_to_a(t_dclist **list_a, t_dclist **list_b)
{
	while (*list_b != NULL)
	{
		ft_pa(list_a, list_b);
	}
	return ;
}
