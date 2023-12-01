/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:12:09 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 22:53:31 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	ft_algo_init(lst);
	ft_print_test(lst);
	ft_lst_dcclear(&lst);
	return (0);
}

void	ft_print_test(t_dclist *lst)
{
	t_dclist *head_a = lst;
	if (lst == NULL)
		return ;
	while (lst->next != NULL && lst->next != head_a)
	{
		ft_printf("Data : %d\n", lst->data);
		// ft_printf("Adress : %p\n", lst);
		// ft_printf("Adress of next element : %p\n", lst->next);
		// ft_printf("Adress of prev element : %p\n", lst->prev);
		lst = lst->next;
	}	
	ft_printf("Data : %d\n", lst->data);
	lst = lst->next;
	ft_printf("Data : %d\n", lst->data);
	// ft_printf("Adress : %p\n", lst);
	// ft_printf("Adress of next element : %p\n", lst->next);
	// ft_printf("Adress of prev element : %p\n", lst->prev);
}
