/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:25 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 15:13:24 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tdc_list	*ft_lstdc_clear(tdc_list **lst)
{
	tdc_list	*tmp;

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
