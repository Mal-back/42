/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:35:51 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 18:50:28 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	parse_av(char *str, t_dclist **list)
{
	long		nb;
	t_dclist	*new_node;

	while (ft_isdigit(*str) || ft_isblank(*str) || ft_is_sign(*str))
	{ 
		nb = ft_atol(&str);
		if (nb < -2147483648 || nb > 2147483647 || check_doublons(nb, *list))
			return (1);
		new_node = ft_lst_dcnew(nb);
		if (new_node == NULL)
			return (1);
		ft_lstdcadd_back(list, new_node);
	}
	if (*str != 0 && *str != 32)
		return (1);
	return (0);
}
