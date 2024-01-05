/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:31:44 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/29 17:31:45 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"

int	is_valid_coord(int x, int y)
{
	if (x < 0 || x > WIN_WIDTH)
		return (0);
	else if (y < 0 || y > WIN_HEIGHT)
		return (0);
	return (1);
}

void	init_tab(int *tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab[i] = 0;
		i++;
	}
}

void	add_value(int x, int y, int *colortab, t_image *buffer)
{
	colortab[0]++;
	colortab[1] += retrieve_color(buffer, x, y, 1);
	colortab[2] += retrieve_color(buffer, x, y, 2);
	colortab[3] += retrieve_color(buffer, x, y, 3);
}

void	compute_blur(t_image *image, t_image *buffer, int x, int y)
{
	int	i;
	int	j;
	int	colortab[4];

	i = -1;
	init_tab(colortab);
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (is_valid_coord(x + j, y + i))
				add_value(x + j, y + i, colortab, buffer);
			j++;
		}
		i++;
	}
	my_pixel_put(image, x, y, colormap(0, colortab[1] / colortab[0], colortab[2] / colortab[0], colortab[3] / colortab[0]));
}

void	ft_blur(t_image *image)
{
	t_image	buffer;
	int		y;
	int		x;

	buffer = *image;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			compute_blur(image, &buffer, x, y);
			x++;
		}
		y++;
	}
	// mlx_destroy_image(image->open_win->mlx, &buffer);
}
