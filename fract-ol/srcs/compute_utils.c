/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:53:42 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/06 17:53:42 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	map(t_image *image, t_complex *complex, int x, int y)
{
	complex->r = (image->slope_x * x) + image->x_origin;
	complex->i = (image->slope_y * y) + image->y_origin;
}

void	set_relative_center_and_slope(t_image *image)
{
	image->slope_x = (4.0 / WIN_WIDTH) * image->zoom;
	image->slope_y = (4.0 / WIN_HEIGHT) * image->zoom;
}

double	is_in_plan(t_complex *nbr)
{
	return ((nbr->r * nbr->r) + (nbr->i * nbr->i));
}

void	round_for_smoothing(t_complex *nbr, t_complex c)
{
	t_complex	tmp;
	int			i;

	i = 0;
	while (i < 3)
	{
		tmp = *nbr;
		nbr->r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		nbr->i = (2. * tmp.r * tmp.i) + c.i;
		i++;
	}
}
