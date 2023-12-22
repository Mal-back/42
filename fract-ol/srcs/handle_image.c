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

int	colormap(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	map(t_image *image, t_complex *complex, int x, int y)
{
	complex->r = image->slope_x * x;
	complex->i = image->slope_y * y;
}

void	set_relative_center_and_slope(t_image *image)
{
	image->relative_x_center = WIN_WIDTH / 2;
	image->relative_y_center = WIN_HEIGHT / 2;
	image->slope_x = 4.0 / WIN_WIDTH;
	image->slope_y = 4.0 / WIN_HEIGHT;
}

double	is_in_plan(t_complex *nbr)
{
	return ((nbr->r * nbr->r) + (nbr->i * nbr->i));
}

void	compute_value_of_pixel(t_image *image, int x, int y)
{
	t_complex	complex_nbr;
	t_complex	tmp;
	int			i;

	map(image, &complex_nbr, x, y);
	i = 0;
	while (i < 1000 && is_in_plan(&complex_nbr) <= 10.0)
	{
		tmp = complex_nbr;
		complex_nbr.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) - 1.0;
		complex_nbr.i = 2. * tmp.r * tmp.i;
		i++;
	}
	if (i == 1000)
		my_pixel_put(image, (x + WIN_WIDTH / 2), y + (WIN_HEIGHT / 2), 0x00000000);
	else
		my_pixel_put(image, (x + WIN_WIDTH / 2), y + (WIN_HEIGHT / 2), colormap(0, 255 - (i * 10), 255 - (i * 50), 255 - (i * 60)));
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
			compute_value_of_pixel(image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx, window->win, image->image, 0, 0);
}
