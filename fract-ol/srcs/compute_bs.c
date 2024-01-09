/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:09:00 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/09 19:09:01 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	dumb_norminette(t_complex *complex_nbr, t_complex c, int max)
{
	int			idx;
	t_complex	tmp;

	idx = 0;
	while (idx < max && is_in_plan(complex_nbr) <= 4.)
	{
		tmp = *complex_nbr;
		complex_nbr->r = fabs((tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r);
		complex_nbr->i = fabs((2. * tmp.r * tmp.i) + c.i);
		idx++;
	}
	return (idx);
}

void	compute_burning_ship(t_image *image, int x, int y)
{
	t_complex	complex_nbr;
	t_complex	tmp;
	t_complex	c;
	int			color;
	int			idx;

	color = 0;
	map(image, &complex_nbr, x, y);
	c.r = complex_nbr.r;
	c.i = complex_nbr.i;
	complex_nbr.r = 0.;
	complex_nbr.i = 0.;
	idx = dumb_norminette(&complex_nbr, c, image->max_iter);
	if (idx < image->max_iter)
	{
		round_for_smoothing(&complex_nbr, c);
		color = def_color(idx + 5, fmax(fabs(complex_nbr.r),
					fabs(complex_nbr.i)), image->max_iter, image);
	}
	my_pixel_put(image, x + (WIN_WIDTH / 2), y + (WIN_HEIGHT / 2), color);
}
