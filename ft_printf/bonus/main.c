/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:38:32 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/15 20:39:10 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	n;
	int n1;
	char *str = NULL;

	n = printf("Refe : ||% s||\n", "lalala");
	n1 = ft_printf("Test : ||% s||\n", "lalala");
	printf("Ref : %d || Test : %d\n", n, n1);
	return (0);
}
