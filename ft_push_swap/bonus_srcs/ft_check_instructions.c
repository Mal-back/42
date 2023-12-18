/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:49:35 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 21:32:29 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "libft.h"

int	ft_check_instructions(char **instructions_tab, char *str)
{
	int	i;

	i = 0;
	while (instructions_tab[i])
	{
		if (!ft_strncmp(str, instructions_tab[i], 5))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
