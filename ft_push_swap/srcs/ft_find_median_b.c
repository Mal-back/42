/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:04:16 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 16:40:30 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_median_b(t_dclist **list)
{
	long		little;
	long		next_little;
	long		big;
	long		next_big;

	little = ft_find_little(list);
	big = ft_find_big(list);
	while (little != big)
	{
		next_big = ft_find_next_big(list, big);
		if (little != next_big)
		{
			next_little = ft_find_next_little(*list, little);
			little = next_little;
		}
		big = next_big;
	}
	return (little);
}
