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

static char	*verify_sorting(t_dclist **list)
{
	int			list_size;

	list_size = ft_lst_dcsize(*list);
	if (ft_is_sorted(*list))
	{
		if (get_next_line(0))
			return ("KO");
		else
			return ("OK");
	}
	else
	{
		ft_parse_instructions(list);
		if (ft_is_sorted(*list) && ft_lst_dcsize(*list) == list_size)
			return ("OK");
		else
			return ("KO");
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_dclist	*lst;

	if (ac < 2)
		return (0);
	i = 1;
	lst = NULL;
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
	ft_printf("%s\n", verify_sorting(&lst));
	ft_lst_dcclear(&lst);
	return (0);
}
