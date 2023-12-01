/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:09:23 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 21:33:59 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_apply_instructions(t_dclist **list_a,
		t_dclist **list_b, int instructions)
{
	if (instructions == 0)
		ft_sa(list_a, 0);
	else if (instructions == 1)
		ft_sb(list_b, 0);
	else if (instructions == 2)
		ft_ss(list_a, list_b);
	else if (instructions == 3)
		ft_pa(list_a, list_b);
	else if (instructions == 4)
		ft_pb(list_b, list_a);
	else if (instructions == 5)
		ft_ra(list_a, 0);
	else if (instructions == 6)
		ft_rb(list_b, 0);
	else if (instructions == 7)
		ft_rr(list_a, list_b);
	else if (instructions == 8)
		ft_rra(list_a, 0);
	else if (instructions == 9)
		ft_rrb(list_b, 0);
	else if (instructions == 10)
		ft_rrr(list_a, list_b);
}
