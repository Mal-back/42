/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_Julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:17:31 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/06 18:17:33 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	compute_julia(t_image *image, int x, int y)
{
	t_complex	tmp;
	t_complex	complex_nbr;
	int			idx;
	int			color;

	idx = 0;
	color = 0;
	map(image, &complex_nbr, x, y);
	while (idx < image->max_iter && is_in_plan(&complex_nbr) <= 4.)
	{
		tmp = complex_nbr;
		complex_nbr.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + image->c.r;
		complex_nbr.i = (2. * tmp.i * tmp.r) + image->c.i;
		idx++;
	}
	if (idx < image->max_iter)
	{
		round_for_smoothing(&complex_nbr, image->c);
		color = def_color(idx + 5, fmax(fabs(complex_nbr.r),
					fabs(complex_nbr.i)), image->max_iter,
				image->colormap[image->color]);
	}
	my_pixel_put(image, x + (WIN_WIDTH / 2), y + (WIN_HEIGHT / 2), color);
}
