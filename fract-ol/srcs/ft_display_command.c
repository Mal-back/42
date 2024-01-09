/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:47:42 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/08 16:47:43 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_display_info(t_main *main)
{
	char	*iter;
	char	*join_str;

	iter = ft_itoa(main->image->max_iter);
	if (!iter)
		kill(main, 1);
	join_str = ft_strjoin("Number of iterations is : ", iter);
	free(iter);
	if (!join_str)
		kill(main, 1);
	mlx_string_put(main->window->mlx, main->window->win, 550, 10, 0x00FFFFFF,
		join_str);
	free(join_str);
}

void	ft_display_command(t_main *main)
{
	if (!main->image->command_display)
		mlx_string_put(main->window->mlx, main->window->win, 5, 10, 0x00FFFFFF,
			"Press H to display command list");
	else
	{
		mlx_string_put(main->window->mlx, main->window->win, 5, 10, 0x00FFFFFF,
			"Use Mouse Wheel to zoom in and out");
		mlx_string_put(main->window->mlx, main->window->win, 5, 20, 0x00FFFFFF,
			"Use Arrow keys to move around the image");
		mlx_string_put(main->window->mlx, main->window->win, 5, 30, 0x00FFFFFF,
			"Use NumPad '+' and '-' to change the number of iterations");
		mlx_string_put(main->window->mlx, main->window->win, 5, 40, 0x00FFFFFF,
			"Use 'f' to enable/disable color smoothing");
		mlx_string_put(main->window->mlx, main->window->win, 5, 50, 0x00FFFFFF,
			"With Julia only : Use 'a' and 'd' to change real value");
		mlx_string_put(main->window->mlx, main->window->win, 5, 60, 0x00FFFFFF,
			"With Julia only : Use 'w' and 's' to change the imaginary value");
		mlx_string_put(main->window->mlx, main->window->win, 5, 70, 0x00FFFFFF,
			"Use 'r' to reset the fractal settings");
		mlx_string_put(main->window->mlx, main->window->win, 5, 80, 0x00FFFFFF,
			"Use 'g' to hide/show GUI");
		mlx_string_put(main->window->mlx, main->window->win, 5, 90, 0x00FFFFFF,
			"Press 'h' to hide command display");
	}
	ft_display_info(main);
}
