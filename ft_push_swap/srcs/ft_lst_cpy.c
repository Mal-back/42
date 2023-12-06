/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:22:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 20:07:50 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_copy(t_dclist **src, t_dclist **dest)
{
	t_dclist	*head_source;
	t_dclist	*new_node;

	head_source = *src;
	*dest = NULL;
	while ((*src)->next != head_source)
	{
		new_node = ft_lst_dcnew((*src)->data);
		if (!new_node)
		{
			ft_lst_dcclear(src);
			ft_lst_dcclear(dest);
			exit(1);
		}
		ft_lstdcadd_back(dest, new_node);
		*src = (*src)->next;
	}
	new_node = ft_lst_dcnew((*src)->data);
	ft_lstdcadd_back(dest, new_node);
	if (!new_node)
	{
		ft_lst_dcclear(src);
		ft_lst_dcclear(dest);
		exit(1);
	}
	*src = (*src)->next;
}
