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
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

int	kill(void *param)
{
	mlx_destroy_window(((t_window *)param)->mlx, ((t_window *)param)->win);
	mlx_destroy_display(((t_window *)param)->mlx);
	free(((t_window *)param)->mlx);
	exit (0);
}
int	handle_key(int key, void *param)
{
	if (key == XK_Escape)
		kill(param);
	else if (key == XK_k)
		write(1, "K\n", 2);
	write(1, "Key pressed !", 13);
	return (0);
}

int	main(int ac, char **av)
{
	t_window	window;
	t_image		image;

	//check_av
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIN_WIDTH, WIN_HEIGHT, "My Fractal");
	image.image = mlx_new_image(window.mlx, WIN_WIDTH, WIN_HEIGHT);
	image.addr = mlx_get_data_addr(image.image, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	handle_image(&image, &window);
	mlx_destroy_image(window.mlx, image.image);
	mlx_hook(window.win, KeyPress, KeyPressMask, handle_key, &window);
	mlx_hook(window.win, 17, 0, kill, &window);
	mlx_loop(window.mlx);
}
