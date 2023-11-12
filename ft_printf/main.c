/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:01 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/11 21:44:59 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	n;
	int n1;
	int m = 789;
	int *k = &m;

	n = printf("Co%d am%x ou %X.o%c. et je mettre %s. Sn %i %i et %u. aue %p. Co!\n", 42, 42, 42, 66, "wesh", 56, -4096, 2147483647, k);	
	n1 = ft_printf("C %d a%x ou %X.%c. et je peux mettre %s. S%i %i %u. e %p.!\n", 42, 42, 42, 66, "wesh", 56, -4096, 2147483647, k);
	printf("Ref : %d, ft : %d", n, n1);
}
