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
#include "libft.h"


void	ft_print_test(t_dclist *lst)
{
	t_dclist *head_a = lst;
	if (lst == NULL)
		return ;
	while (lst->next != NULL && lst->next != head_a)
	{
		ft_printf("Data : %d\n", lst->data);
		lst = lst->next;
	}	
	ft_printf("Data : %d\n", lst->data);
}

void	ft_parse_instructions(t_dclist **list_a)
{
	t_dclist	*list_b;
	char		**instructions_tab;
	char		*str;
	int			i;
	int			instruction_number;

	i = 0;
	list_b = NULL;
	str = NULL;
	instructions_tab = ft_split("sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n", 32);
	ft_printf("Starting list A :\n");
	ft_print_test(*list_a);
	while (str || i == 0)
	{
		str = get_next_line(0);
		if (str)
		{
			instruction_number = ft_check_instructions(instructions_tab, str);
			ft_printf("\n-------------------\nInstructions applied : %s\n", str);
			ft_apply_instructions(list_a, &list_b, instruction_number);
			if (instruction_number == -1)
				free_and_exit(list_a, &list_b, &instructions_tab, str);
			free(str);
			ft_printf("List A : \n");
			ft_print_test(*list_a);
			ft_printf("\n\n\nList B : \n");
			ft_print_test(list_b);
		}
		i++;
	}
	ft_lst_dcclear(&list_b);
	free_tab(&instructions_tab);
}
