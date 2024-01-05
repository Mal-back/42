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

int	rounded_colormap(int zoom_tracker, float r_f, float g_f, float b_f)
{
	int	r;
	int	g;
	int	b;

	if (zoom_tracker % 3 == 0)
	{
		r = round(g_f * 255);
		g = round(b_f * 255);
		b = round(r_f * 255);
	}
	else if (zoom_tracker % 2 == 0)
	{
		r = round(b_f * 255);
		g = round(r_f * 255);
		b = round(g_f * 255);
	}
	else
	{
		r = round(r_f * 255);
		g = round(g_f * 255);
		b = round(b_f * 255);
	}
	return (colormap(0, r, g, b));
}

int	def_color(int hue, int zoom_tracker)
{
	float	div_hue;
	float	chroma;
	float	x;
	float	m;

	div_hue = hue / 60.;
	chroma = (1 - fabs(2 * LIGHT - 1)) * SATURATION;
	x = chroma * (1 - abs((int)div_hue % 2) - 1);
	m = LIGHT - (chroma / 2);
	if (div_hue <= 1)
		return (rounded_colormap(zoom_tracker, chroma + m, x + m, m));
	else if (div_hue <= 2)
		return (rounded_colormap(zoom_tracker, x + m, chroma + m, m));
	else if (div_hue <= 3)
		return (rounded_colormap(zoom_tracker, m, chroma + m, x + m));
	else if (div_hue <= 4)
		return (rounded_colormap(zoom_tracker, m, x + m, chroma + m));
	else if (div_hue <= 5)
		return (rounded_colormap(zoom_tracker, x + m, m, chroma + m));
	else
		return (rounded_colormap(zoom_tracker, chroma + m, m, x + m));
}
