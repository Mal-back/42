/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:12:09 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/26 20:51:12 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// void	ft_test(t_dclist *list)
// {
// 	t_dclist	*list_a;
// 	t_dclist	*list_b;
// 	t_dclist	*head_a;
// 	t_dclist	*head_b;
//
// 	list_a = list;
// 	list_b = NULL;
// 	ft_pb(&list_b, &list_a);
// 	ft_pb(&list_b, &list_a);
// 	ft_pb(&list_b, &list_a);
// 	ft_sa(&list_a, 1);
// 	ft_rrb(&list_b, 1);
// 	head_a = list_a;
// 	head_b = list_b;
// 	ft_printf("List_a : \n");
// 	while (list_a->next != head_a)
// 	{
// 		ft_printf("%d\n", list_a->data);
// 		list_a = (list_a->next);
// 	}
// 	if (list_a)
// 		ft_printf("%d\n", list_a->data);
// 	ft_printf("List_b : \n");
// 	while (list_b->next != head_b)
// 	{
// 		ft_printf("%d\n", list_b->data);
// 		list_b = (list_b->next);
// 	}
// 	if (list_b)
// 		ft_printf("%d\n", list_b->data);
// 	ft_lst_dcclear(&head_a);
// 	ft_lst_dcclear(&head_b);
// }

int	main(int ac, char **av)
{
	int			i;
	t_dclist	*lst;

	i = 1;
	lst = NULL;
	if (ac < 2)
	{
		return (0);
	}
	while (i < ac)
	{
		if (parse_av(av[i], &lst))
		{
			ft_putendl_fd("Error", 2);
			lst = ft_lst_dcclear(&lst);
			return (1);
		}
		i++;
	}
	lst = ft_algo_init(lst);
	return (0);
}
