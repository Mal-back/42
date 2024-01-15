/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:56:05 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/15 10:56:06 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <unistd.h>

static int	assemble_pwd(t_main	*main, int j)
{
	char	*full_path;

	full_path = ft_strjoin(main->pwd, *main->cmds[j]);
	if (!full_path)
		ft_clean_exit(main, 1);
	if (access(full_path, X_OK) == 0)
	{
		free(*main->cmds[j]);
		*main->cmds[j] = full_path;
		return (1);
	}
	if (access(*main->cmds[j], X_OK) == 0)
		return (1);
	return (0);
}

void	assemble_command(t_main *main, int j)
{
	int		i;
	char	*full_path;

	i = 0;
	while (main->possible_paths[i])
	{
		full_path = ft_strjoin(main->possible_paths[i], *main->cmds[j]);
		if (!full_path)
			ft_clean_exit(main, 1);
		if (access(full_path, X_OK) == 0)
		{
			free(*main->cmds[j]);
			*main->cmds[j] = full_path;
			return ;
		}
		else
			free (full_path);
		i++;
	}
	assemble_pwd(main, j);
}
