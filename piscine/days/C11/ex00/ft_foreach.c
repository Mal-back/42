/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:01:11 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/13 18:59:54 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int					i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*void	ft_putnbr(int nb)
{
	char				c;

	c = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
}

int	main(void)
{
	int		tab[] = {22,45,889,456789,1,889,666,1312};
	ft_foreach(tab, 8, &ft_putnbr);
}*/
