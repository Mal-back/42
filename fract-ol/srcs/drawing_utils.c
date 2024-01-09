/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:57:11 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/22 13:57:12 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	colormap(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_smoothing(double mu, int count, t_smoothing *smooth_info)
{
	smooth_info->color1 = (int)mu;
	smooth_info->reminder_2 = mu - smooth_info->color1;
	smooth_info->reminder_1 = 1 - smooth_info->reminder_2;
	smooth_info->color1 %= count;
	smooth_info->color2 = (smooth_info->color1 + 1) % count;
}

int	def_color(int idx, double z, int max_iter, t_image *image)
{
	double		mu;
	t_color		final_color;
	t_smoothing	smooth_info;

	mu = idx + 1 - log(log(z)) / log(2.);
	if (image->smoothing)
		mu = mu / max_iter * 7;
	init_smoothing(mu, 7, &smooth_info);
	final_color.red = (unsigned char)(image->colormap[image->color]
		[smooth_info.color1].red * smooth_info.reminder_1
			+ image->colormap[image->color][smooth_info.color2].red
			* smooth_info.reminder_2);
	final_color.green = (unsigned char)(image->colormap[image->color]
		[smooth_info.color1].green * smooth_info.reminder_1
			+ image->colormap[image->color][smooth_info.color2].green
			* smooth_info.reminder_2);
	final_color.blue = (unsigned char)(image->colormap[image->color]
		[smooth_info.color1].blue * smooth_info.reminder_1
			+ image->colormap[image->color][smooth_info.color2].blue
			* smooth_info.reminder_2);
	return (colormap(0, final_color.red, final_color.green, final_color.blue));
}
