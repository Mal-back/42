/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:08:17 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/13 19:16:43 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int					*map;
	int					i;

	map = malloc(length * sizeof (int));
	i = 0;
	while (i < length)
	{
		map[i] = f(tab[i]);
		i++;
	}
	return (map);
}
/*int ft_incr(int a)
{
	a += 10;
	return (a);
}
#include <stdio.h>
int main(void)
{
	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	*map;

	map = ft_map(tab, 10, &ft_incr);
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", map[i]);
		i++;
	}
	return (0);
}*/
