/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:35:51 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 16:41:46 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_av(char *str, tdc_list **list)
{
	long	nb;
	tdc_list	*new_node;

	while (ft_isdigit(*str) || ft_isblank(*str)|| ft_is_sign(*str))
	{
			nb = ft_atol(&str);
			if (nb < -2147483648 || nb > 2147483647 || check_doublons(nb, *list))
				return (1);
			new_node = ft_lstdc_new(&nb);
			if (new_node == NULL)
				return (1);
			ft_lstdcadd_back(list, new_node);
			str++;
	}
	if (*str != 0)
		return (1);
	return (0);
}
