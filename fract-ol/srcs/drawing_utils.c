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
#include <math.h>
#include <stdio.h>

void	my_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

char	retrieve_color(t_image *img, int x, int y, int i)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	// printf("%i\n", *dst);
	return (*(unsigned char *)(dst + i));
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

void	init_color(t_color *colortab)
{
	colortab[4].red = 133;
	colortab[4].green = 129;
	colortab[4].blue = 17;
	colortab[1].red = 105;
	colortab[1].green = 101;
	colortab[1].blue = 8;
	colortab[2].red = 38;
	colortab[2].green = 44;
	colortab[2].blue = 224;
	colortab[3].red = 39;
	colortab[3].green = 42;
	colortab[3].blue = 143;
	colortab[0].red = 24;
	colortab[0].green = 47;
	colortab[0].blue = 222;
}

int	def_color(int idx, double z, int max_iter)
{
	double		mu;
	t_color		colortab[5];
	t_color		final_color;
	t_smoothing	smooth_info;

	init_color(colortab);
	mu = idx + 1 - log(log(z)) / log(2.);
	// mu = mu / max_iter * 5;
	init_smoothing(mu, 5, &smooth_info);
	final_color.red = (unsigned char)(colortab[smooth_info.color1].red
			* smooth_info.reminder_1 + colortab[smooth_info.color2].red
			* smooth_info.reminder_2);
	final_color.green = (unsigned char)(colortab[smooth_info.color1].green
			* smooth_info.reminder_1 + colortab[smooth_info.color2].green
			* smooth_info.reminder_2);
	final_color.blue = (unsigned char)(colortab[smooth_info.color1].blue
			* smooth_info.reminder_1 + colortab[smooth_info.color2].blue
			* smooth_info.reminder_2);
	return (colormap(0, final_color.red, final_color.green, final_color.blue));
}
