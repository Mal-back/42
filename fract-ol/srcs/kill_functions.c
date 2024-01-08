/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:20:42 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/08 18:21:05 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	kill_cross(t_main *param)
{
	kill(param, 0);
	return (0);
}

void	kill_buttons(t_main *main)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (main->button[i].image)
			mlx_destroy_image(main->window->mlx, main->button[i].image);
		i++;
	}
}

int	kill(t_main *param, int code)
{
	kill_buttons(param);
	if (param->image->image)
		mlx_destroy_image(param->window->mlx, param->image->image);
	if (param->window->win)
		mlx_destroy_window(param->window->mlx, param->window->win);
	if (param->window->mlx)
	{
		mlx_destroy_display(param->window->mlx);
		free(param->window->mlx);
	}
	free_struct(param);
	exit (code);
}
