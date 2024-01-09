/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:33:58 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/22 12:33:58 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	identify_fractal(char *av, char **valid_set)
{
	int	i;

	i = 0;
	while (valid_set[i])
	{
		if (!ft_strncmp(av, valid_set[i], ft_strlen(valid_set[i] + 1)))
			return (i);
		i++;
	}
	return (-1);
}

static int	is_in_range(double d)
{
	if (d > 2. || d < -2.)
		return (0);
	return (1);
}

static int	parse_julia(char **av, t_image *image)
{
	if (invalid_number(av[0]) || invalid_number(av[1]))
		return (1);
	image->c.r = ft_atod(av[0]);
	image->c.i = ft_atod(av[1]);
	if (!is_in_range(image->c.r) || !is_in_range(image->c.i))
		return (1);
	return (0);
}

void	check_av(int ac, char **av, t_main *main)
{
	char	**fractal;
	int		i;

	fractal = ft_split("Mandelbrot Julia Burning_ship", ' ');
	if (ac < 2 || !fractal)
		display_help(fractal, main);
	i = identify_fractal(av[1], fractal);
	if (i == -1)
		display_help(fractal, main);
	if (i == 0 || i == 2)
	{
		if (ac != 2)
			display_help(fractal, main);
		main->image->fractal = i;
	}
	else if (i == 1)
	{
		if (ac != 4 || parse_julia(av + 2, main->image))
			display_help(fractal, main);
		main->image->fractal = i;
	}
	ft_free_tab(fractal);
}

int	main(int ac, char **av)
{
	t_main	main;

	main.image = malloc(sizeof (t_image));
	if (!main.image)
		return (1);
	main.window = malloc(sizeof (t_window));
	if (!main.image || !main.window)
	{
		free_struct(&main);
		exit (1);
	}
	check_av(ac, av, &main);
	init_window(&main);
	return (0);
}
