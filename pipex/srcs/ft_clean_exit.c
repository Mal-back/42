/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:47 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/12 16:53:47 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	ft_clean_exit(t_main *main, int code)
{
	int	i;

	close(main->fd_infile);
	close(main->fd_outfile);
	if (main->possible_paths)
		ft_free_tab(main->possible_paths);
	if (main->cmds)
	{
		i = 0;
		while (main->cmds[i])
		{
			ft_free_tab(main->cmds[i]);
			i++;
		}
		free(main->cmds);
	}
	if (main->pwd)
		free(main->pwd);
	exit (code);
}
