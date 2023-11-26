/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:25 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/26 19:37:09 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist	*ft_lst_dcclear(t_dclist **lst)
{
	t_dclist	*tmp;
	t_dclist	*tmp2;

	if (!lst || !*lst)
		return (NULL);
	tmp = *lst;
	if (tmp->next == NULL)
	{
		free(tmp);
		return (NULL);
	}
	while (tmp->next != *lst)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(tmp);
	lst = NULL;
	return (NULL);
}
