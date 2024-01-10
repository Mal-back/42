/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:59:08 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/06 15:59:09 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	send_image(t_main *main)
{
	int	i;
	int	y_button;

	i = 0;
	y_button = 5;
	if (main->image->refresh)
	{
		mlx_put_image_to_window(main->window->mlx, main->window->win,
			main->image->image, 0, 0);
		if (main->image->gui)
		{
			while (i < 5)
			{
				mlx_put_image_to_window(main->window->mlx, main->window->win,
					main->button[i].image, 1100, y_button);
				y_button += 40;
				i++;
			}
			ft_display_command(main);
		}
	}
}

void	handle_image(t_main *main)
{
	int	y;
	int	x;

	set_relative_center_and_slope(main->image);
	y = WIN_HEIGHT / -2;
	while (y <= WIN_HEIGHT / 2)
	{
		x = WIN_WIDTH / -2;
		while (x <= WIN_WIDTH / 2)
		{
			main->compute[main->image->fractal](main->image, x, y);
			x++;
		}
		y++;
	}
	send_image(main);
}

void	init_image(t_image *image)
{
	image->addr = mlx_get_data_addr(image->image, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	image->zoom = 1.;
	image->zoom_tracker = 1;
	image->max_iter = 40;
	image->x_origin = 0;
	image->y_origin = 0;
	image->command_display = 0;
	image->refresh = 1;
	image->smoothing = 0;
	image->gui = 1;
	image->rand_color = 0;
	image->color = RED;
}

void	init_function(t_main *main)
{
	int	i;

	i = 0;
	main->window->mlx = NULL;
	main->window->win = NULL;
	main->image->image = NULL;
	while (i < 5)
	{
		main->button[i].image = NULL;
		i++;
	}
	main->compute[0] = compute_mandelbrot;
	main->compute[1] = compute_julia;
	main->compute[2] = compute_burning_ship;
}

void	init_window(t_main *main)
{
	init_function(main);
	init_color(main);
	main->window->mlx = mlx_init();
	if (!main->window->mlx)
		kill(main, 1);
	main->window->win = mlx_new_window(main->window->mlx, WIN_WIDTH,
			WIN_HEIGHT, "My Fractal");
	if (!main->window->mlx)
		kill(main, 1);
	main->image->image = mlx_new_image(main->window->mlx,
			WIN_WIDTH, WIN_HEIGHT);
	if (!main->image->image)
		kill(main, 1);
	init_image(main->image);
	init_button(main);
	handle_image(main);
	mlx_mouse_hook(main->window->win, handle_mouse, main);
	mlx_hook(main->window->win, KeyPress, KeyPressMask, handle_key, main);
	mlx_hook(main->window->win, 17, 0, kill_cross, main);
	mlx_loop(main->window->mlx);
}
