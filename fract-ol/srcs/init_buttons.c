/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:43:51 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/08 17:43:52 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "libft.h"

void	init_button(t_main *main)
{
	int		i;
	char	**path_tab;

	i = 0;
	path_tab = ft_split(BUTTON_1 BUTTON_2 BUTTON_3 BUTTON_4 BUTTON_5, ' ');
	if (!path_tab)
		kill(main, 1);
	while (i < 5)
	{
		main->button[i].endian = 25;
		main->button[i].line_length = 80;
		main->button[i].image = mlx_xpm_file_to_image(main->window->mlx,
				path_tab[i], &main->button[i].line_length,
				&main->button[i].endian);
		if (!main->button[i].image)
		{
			ft_putstr_fd("Error while loading ressources, couldn't open : ", 2);
			ft_putendl_fd(path_tab[i], 2);
			ft_free_tab(path_tab);
			kill(main, 1);
		}
		i++;
	}
	ft_free_tab(path_tab);
}
