/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:12:09 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 13:18:18 by vlevy            ###   ########.fr       */
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
	lst = ft_algo_init(lst);
	ft_lst_dcclear(&lst);
	return (0);
}
