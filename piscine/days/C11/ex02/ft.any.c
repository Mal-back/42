/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:08:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 12:22:04 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int					i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

/*int	ft_str_is_numeric(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main(int ac, char **argv)
{
	printf("%d\n", ft_any(argv + 1, ft_str_is_numeric));
	return (0);
}*/
