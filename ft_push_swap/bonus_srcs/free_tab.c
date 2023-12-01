/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:38:18 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 21:25:15 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	free_tab(char ***tab)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *tab;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
