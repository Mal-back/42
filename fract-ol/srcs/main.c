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
#include "libft.h"
#include <stdio.h>

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

static void	display_help(char **tab)
{
	ft_free_tab(tab);
	ft_printf("Wrong Usage, here is the correct one :\n");
	ft_printf("./fractol [fractal] [Julia Real value] [Julia Imaginary Value]");
	ft_printf(" [ColorPalette]\n");
	ft_printf("Available Fractal : MandelBrot , Julia, Boudhabrot\n");
	ft_printf("If you choose Julia, Real and imaginary values are mandatory");
	ft_printf(" and must be contained in the range [-2.0, 2.0]\n");
	ft_printf("They must be ignored for the other fractals\n");
	ft_printf("ColorPalette is optional. The choices are :");
	ft_printf(" Red, Blue, Green, Rainbow and Psychedelic.");
	ft_printf(" Default is rainbow.\n");
	exit (0);
}

void	check_av(int ac, char **av)
{
	char	**fractal;
	int		i;

	fractal = ft_split("Mandelbrot Julia Boudhabrot", ' ');
	if (ac < 2)
		display_help(fractal);
	i = identify_fractal(av[1], fractal);	
	if (i == 0)
		printf("Mandy !\n");
		// parse_mandelbrot;
	else if (i == 1)
		printf("Julia !\n");
		// parse_julia;
	else if (i == 2)
		printf("Boudha !\n");
		// parse_boudhabrot;
	else
		display_help(fractal);
}

int	main(int ac, char **av)
{
	t_window	window;
	t_image		image;

	check_av(ac, av);
	// window.mlx = mlx_init();
	// window.win = mlx_new_window(window.mlx, WIN_WIDTH, WIN_HEIGHT, "My Fractal");
	// image.image = mlx_new_image(window.mlx, WIN_WIDTH, WIN_HEIGHT);
	// image.addr = mlx_get_data_addr(image.image, &image.bits_per_pixel,
	// 		&image.line_length, &image.endian);
	// image.zoom = 1.;
	// image.zoom_tracker = 1;
	// image.max_iter = 40;
	// image.x_origin = 0;
	// image.y_origin = 0;
	// image.open_win = &window;
	// handle_image(&image, &window);
	// mlx_mouse_hook(window.win, handle_mouse, &image);
	// mlx_hook(window.win, KeyPress, KeyPressMask, handle_key, &image);
	// mlx_hook(window.win, 17, 0, kill, &image);
	// mlx_loop(window.mlx);
}
