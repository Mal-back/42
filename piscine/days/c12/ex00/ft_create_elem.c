/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:33:59 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/20 20:39:51 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;
	voidi	*ptr;

	list = malloc(sizeof (t_list));
	list->next = NULL;
	list->data = data;
	ptr = &list;
	return (ptr);
}

/*#include <stdio.h>
int main(void)
{
	int	a = 132;
	t_list	*ptr;
	int	*result;

	ptr = NULL;
	ptr = ft_create_elem(&a);
	result = ptr->data;
	printf("%d\n", *result);
}*/
