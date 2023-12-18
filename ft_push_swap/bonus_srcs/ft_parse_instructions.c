/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:33:56 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/04 20:14:23 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_parse_instructions(t_dclist **list_a)
{
	t_dclist	*list_b;
	char		**instructions_tab;
	char		*str;
	int			instruction_number;

	str = NULL;
	str = get_next_line(0);
	list_b = NULL;
	instructions_tab = ft_split("sa\n sb\n ss\n pa\n pb\n "
			"ra\n rb\n rr\n rra\n rrb\n rrr\n", 32);
	while (str)
	{
		if (str)
		{
			instruction_number = ft_check_instructions(instructions_tab, str);
			if (instruction_number == -1)
				free_and_exit(list_a, &list_b, &instructions_tab, str);
			ft_apply_instructions(list_a, &list_b, instruction_number);
			free(str);
			str = get_next_line(0);
		}
	}
	ft_lst_dcclear(&list_b);
	free_tab(&instructions_tab);
}
