/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:11:10 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 21:29:22 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_retrieve_length(long n, size_t	*len)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_retrieve_length(n / base_len, len);
	*len += 1;
	return ;
}

static void	fill_str(char	*str, size_t	*f, long n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		fill_str(str, f, n / base);
	str[*f] += base[n % base_len];
	*f += 1;
}

char	*ft_itoa_ptr(unsigned long long nb, char *base)
{
	char	*str;
	size_t	f;
	size_t	len;

	f = 0;
	len = 0;
	if (n < 0)
	{
		f = 1;
		n *= -1;
	}
	ft_retrieve_length(n, &len, base);
	len += f;
	str = ft_calloc((len + 1), sizeof (char));
	if (str != NULL)
	{
		str[len] = 0;
		if (f == 1)
			str[0] = '-';
		fill_str(str, &f, n, base, base_len);
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;
	str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
