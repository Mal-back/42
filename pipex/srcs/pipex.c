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

static void	wait_child(t_main *main, pid_t pid)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		wait(NULL);
	ft_clean_exit(main, WEXITSTATUS(status));
}

static void	dumb_norminette(t_main *main)
{
	if (pipe(main->pipe) == -1)
		ft_clean_exit(main, PIPE_ERROR);
}

void	init_pipex(t_main *main)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (main->cmds[i])
	{
		if (i)
		{
			close(main->pipe[WRITE_ENTRY]);
			main->read_entry = main->pipe[READ_ENTRY];
		}
		if (i != main->command_number - 1)
			dumb_norminette(main);
		pid = fork();
		if (pid == -1)
			ft_clean_exit(main, FORK_ERROR);
		if (!pid)
			handle_command(main, i);
		if (i)
			close(main->read_entry);
		i++;
	}
	wait_child(main, pid);
}
