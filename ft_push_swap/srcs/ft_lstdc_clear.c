/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:25 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:43:52 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist	*ft_lst_dcclear(t_dclist **lst)
{
	t_dclist	*tmp;

	if (!lst || !*lst)
		return (NULL);
	tmp = *lst;
	if (tmp->next == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp = tmp->next;
	while (tmp->next != *lst)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
	free(*lst);
	lst = NULL;
	return (NULL);
}
