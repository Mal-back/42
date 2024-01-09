/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:31:33 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/05 16:31:55 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	handle_key_next(int key, t_main *param)
{
	if (key == XK_h)
		param->image->command_display ^= 1;
	else if (key == XK_g)
		param->image->gui ^= 1;
	else if (key == XK_w && param->image->fractal == JULIA)
		param->image->c.i += 0.01;
	else if (key == XK_s && param->image->fractal == JULIA)
		param->image->c.i -= 0.01;
	else if (key == XK_d && param->image->fractal == JULIA)
		param->image->c.r += 0.01;
	else if (key == XK_a && param->image->fractal == JULIA)
		param->image->c.r -= 0.01;
	else if (key == XK_r)
		init_image(param->image);
	else
		param->image->refresh = 0;
}

int	handle_key(int key, t_main *param)
{
	param->image->refresh = 1;
	if (key == XK_Escape)
		kill(param, 0);
	else if (key == XK_KP_Add)
		param->image->max_iter += 10;
	else if (key == XK_KP_Subtract && param->image->max_iter > 20)
		param->image->max_iter -= 10;
	else if (key == XK_Up)
		param->image->y_origin -= 0.25 * param->image->zoom;
	else if (key == XK_Down)
		param->image->y_origin += 0.25 * param->image->zoom;
	else if (key == XK_Left)
		param->image->x_origin -= 0.25 * param->image->zoom;
	else if (key == XK_Right)
		param->image->x_origin += 0.25 * param->image->zoom;
	else if (key == XK_f)
		param->image->smoothing ^= 1;
	else
		handle_key_next(key, param);
	handle_image(param);
	return (0);
}

static void	handle_colorshift(int x, int y, t_main *param)
{
	int	i;
	int	ystart;

	i = 0;
	ystart = 5;
	while (i < 5)
	{
		if (x >= 1100 && x <= 1180)
		{
			if (y >= ystart && y <= ystart + 25)
			{
				if (i <= 3)
				{
					param->image->color = i;
					param->image->refresh = 1;
					param->image->rand_color = 0;
				}
				else
					param->image->rand_color = 1;
				i = 10;
			}
		i++;
		ystart += 40;
		}
	}
}

static void	update_color(t_main *param)
{
	if (param->image->rand_color)
	{
		param->image->color++;
		if (param->image->color > 3)
			param->image->color = 0;
	}
}

int	handle_mouse(int key, int x, int y, t_main *param)
{
	if (key == 1 && param->image->gui)
		handle_colorshift(x, y, param);
	if (key == 4)
	{
		param->image->zoom *= 0.9;
		param->image->refresh = 1;
		param->image->max_iter += 2;
		param->image->zoom_tracker++;
		param->image->x_origin += (x - WIN_WIDTH / 2.)
			* (4. / WIN_WIDTH) * param->image->zoom;
		param->image->y_origin += (y - WIN_HEIGHT / 2.)
			* (4. / WIN_HEIGHT) * param->image->zoom;
		update_color(param);
	}
	if (key == 5)
	{
		param->image->zoom *= 1.1;
		param->image->refresh = 1;
		param->image->max_iter -= 2;
		param->image->zoom_tracker--;
		update_color(param);
	}
	handle_image(param);
	return (0);
}
