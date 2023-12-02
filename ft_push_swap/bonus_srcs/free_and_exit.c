/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:32:52 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 16:55:53 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "libft.h"

void	free_and_exit(t_dclist **list_a, t_dclist **list_b,
		char ***tab, char *str)
{
	ft_lst_dcclear(list_a);
	ft_lst_dcclear(list_b);
	free(str);
	free_tab(tab);
	ft_putendl_fd("Error", 1);
	exit(1);
}
