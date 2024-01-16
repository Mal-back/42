/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:02:30 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/15 15:02:31 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_main *main)
{
	int		i;
	pid_t	pid;
	int		status;

	i = 0;
	while (main->cmds[i])
	{
		if (i)
			close(main->pipe[WRITE_ENTRY]);
		main->read_entry = main->pipe[READ_ENTRY];
		if (pipe(main->pipe) == -1)
			ft_clean_exit(main, PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			ft_clean_exit(main, FORK_ERROR);
		if (!pid)
			handle_command(main, i);
		if (i)
			close(main->read_entry);
		i++;
	}
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		wait(NULL);
	ft_clean_exit(main, WEXITSTATUS(status));
}
