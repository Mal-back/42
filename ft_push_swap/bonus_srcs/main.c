/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 03:19:58 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 21:43:35 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "libft.h"

int	main(int ac, char **av)
{
	int			i;
	int			list_size;
	t_dclist	*lst;

	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (parse_av(av[i], &lst))
		{
			ft_putendl_fd("Error", 2);
			ft_lst_dcclear(&lst);
			return (1);
		}
		i++;
	}
	list_size = ft_lst_dcsize(lst);
	ft_parse_instructions(&lst);
	if (ft_is_sorted(lst) && ft_lst_dcsize(lst) == list_size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lst_dcclear(&lst);
	return (0);
}
