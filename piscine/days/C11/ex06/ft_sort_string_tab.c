/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:22:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 13:16:46 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int					i;

	i = 0;
	if (s1[i] == 0 && s2[i] == 0)
		return (0);
	if (s1[i] == 0)
		return (-1);
	if (s2[i] == 0)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int				i;
	int				j;
	int				len;
	char			*temp;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*#include <stdio.h>
int main(int ac, char **av)
{
	ft_sort_string_tab(av);
	int i = 0;
	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}*/
