/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdstdin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:17:26 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/19 17:40:09 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int main(void)
{
	char buff[1];
	char *str;
	int i = 0;
	int size = 0;


	str = malloc(1024 * 1024 * sizeof (char));
	while (read(0, buff, 1))
	{
		str = ft_strcat(str, buff);
	}
	printf("\n%s\n", str);
	//write(1, &str[0], 22);
}
