/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:29:07 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/15 12:29:07 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	append_backslash(t_main *main)
{
	int		i;
	char	*joined_str;

	i = 0;
	while (main->possible_paths[i])
	{
		joined_str = ft_strjoin(main->possible_paths[i], "/");
		if (!joined_str)
			ft_clean_exit(main, MALLOC);
		free (main->possible_paths[i]);
		main->possible_paths[i] = joined_str;
		i++;
	}
	joined_str = ft_strjoin(main->pwd, "/");
	if (!joined_str)
		ft_clean_exit(main, MALLOC);
	free (main->pwd);
	main->pwd = joined_str;
	return ;
}
