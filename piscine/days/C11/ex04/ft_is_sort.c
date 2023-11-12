/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:30:04 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 12:39:36 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int					i;

	i = 0;
	while(i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return(0);
		i++;
	}
	return (1);
}

/*int	ft_sort(int a, int b)
{
	return (b - a);
}
#include <stdio.h>
int	main(void)
{
	int	tab[] = {0,1,2,3,4,5,6,7,9,8};

	printf("%d\n", ft_is_sort(tab, 10, ft_sort));
	return (0);
}*/
