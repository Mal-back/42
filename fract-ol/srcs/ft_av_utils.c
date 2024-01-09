/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:17:38 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/06 14:17:39 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	free_struct(t_main *main)
{
	if (main->image)
		free(main->image);
	if (main->window)
		free(main->window);
	return ;
}

int	invalid_number(char *str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != '.' || !flag)
				return (1);
		}
		flag = 1;
		i++;
	}
	return (0);
}

void	display_help(char **tab, t_main *main)
{
	ft_free_tab(tab);
	free_struct(main);
	ft_printf("Wrong Usage, here is the correct one :\n");
	ft_printf("./fractol [fractal] [Julia Real value] \
	[Julia Imaginary Value]\n");
	ft_printf("Available Fractal : MandelBrot , Julia, Burning_ship\n");
	ft_printf("If you choose Julia, Real and imaginary values are mandatory");
	ft_printf(" and must be contained in the range [-2.0, 2.0]\n");
	ft_printf("They must be ignored for the other fractals.\n");
	exit (0);
}

void	print_parsing_error(int error_tag, int i, int j, char *str)
{
	int	line_number;

	line_number = 15 + i + (i * 3) + j;
	ft_putendl_fd("Error while reading color config file", 2);
	ft_putstr_fd("In file ", 2);
	ft_putendl_fd(str, 2);
	if (error_tag == -1)
		ft_putstr_fd("Parsing Error near line ", 2);
	if (error_tag == -2)
		ft_putstr_fd("Out of range value at line ", 2);
	ft_putnbr_fd(line_number, 2);
	ft_putchar_fd('\n', 2);
	return ;
}
