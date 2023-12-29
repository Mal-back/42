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
#include <stdio.h>
#include "libft.h"
#include "mlx.h"

int	kill(t_image *param)
{
	mlx_destroy_image(param->open_win->mlx, param->image);
	mlx_destroy_window(param->open_win->mlx, param->open_win->win);
	mlx_destroy_display(param->open_win->mlx);
	free(param->open_win->mlx);
	exit (0);
}
int	handle_key(int key, t_image *param)
{
	if (key == XK_Escape)
		kill(param);
	else if (key == XK_KP_Add)
		param->max_iter += 10;
	else if (key == XK_KP_Subtract)
		param->max_iter -= 10;
	// else if (key == XK_Up)
	// 	
	handle_image(param, param->open_win);
	return (0);
}

int	handle_mouse(int key, int x, int y, t_image *param)
{
	if (key == 4)
	{
		param->zoom *= 0.95;
		param->max_iter += 2;
		param->x_origin += (x - WIN_WIDTH / 2.) * (4. / WIN_WIDTH) * param->zoom;
		param->y_origin += (y - WIN_HEIGHT / 2.) * (4. / WIN_HEIGHT) * param->zoom;
		printf("X : %lf, Y : %lf\n", param->x_origin, param->y_origin);
		handle_image(param, param->open_win);
	}
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
	image.zoom = 1.;
	image.max_iter = 40;
	image.x_origin = 0;
	image.y_origin = 0;
	image.open_win = &window;
	handle_image(&image, &window);
	mlx_mouse_hook(window.win, handle_mouse, &image);
	mlx_hook(window.win, KeyPress, KeyPressMask, handle_key, &image);
	mlx_hook(window.win, 17, 0, kill, &image);
	mlx_loop(window.mlx);
}
