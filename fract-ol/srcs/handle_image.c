/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:16:45 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/22 13:16:46 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include <stdio.h>

int	colormap(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	map(t_image *image, t_complex *complex, int x, int y)
{
	complex->r = (image->slope_x * (x + image->x_origin));
	complex->i = (image->slope_y * (y + image->y_origin));
}

void	set_relative_center_and_slope(t_image *image)
{
	image->slope_x = (4.0 / WIN_WIDTH) * image->zoom;
	image->slope_y = (4.0 / WIN_HEIGHT) * image->zoom;
	printf("Slope_x : %lf, slope_y : %lf\n", image->slope_x, image->slope_y);
}

double	is_in_plan(t_complex *nbr)
{
	return ((nbr->r * nbr->r) + (nbr->i * nbr->i));
}

void	compute_value_of_pixel(t_image *image, int x, int y)
{
	t_complex	complex_nbr;
	t_complex	tmp;
	t_complex	c;
	int			idx;

	map(image, &complex_nbr, x, y);
	c.r = complex_nbr.r;
	c.i = complex_nbr.i;
	complex_nbr.r = 0.;
	complex_nbr.i = 0.;
	// printf("x : %lf, y : %lf \n", complex_nbr.r, complex_nbr.i);
	idx = 0;
	while (idx < image->max_iter && is_in_plan(&complex_nbr) <= 4.)
	{
		tmp = complex_nbr;
		complex_nbr.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		complex_nbr.i = (2. * tmp.r * tmp.i) + c.i;
		idx++;
	}
	if (idx == image->max_iter)
		my_pixel_put(image, (x + WIN_WIDTH / 2), y + (WIN_HEIGHT / 2), 0x00000000);
	else
		my_pixel_put(image, (x + WIN_WIDTH / 2), y + (WIN_HEIGHT / 2), colormap(0, 255 - (idx * 50), 255 - (idx * 25), 255 - (idx * 60)));
}

void	handle_image(t_image *image, t_window *window)
{
	int	y;
	int	x;

	set_relative_center_and_slope(image);
	y = WIN_HEIGHT / -2;
	while (y < WIN_HEIGHT / 2)
	{
		x = WIN_WIDTH / -2;
		while (x < WIN_WIDTH / 2)
		{
			compute_value_of_pixel(image, x , y);
			x++;
		}
		y++;
	}
	// printf("X : %d, Y : %d\n", x, y);
	mlx_put_image_to_window(window->mlx, window->win, image->image, 0, 0);
}
