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
#include <stdlib.h>
#include <unistd.h>

static void	last_cmds(t_main *main, int idx)
{
	pid_t	pid;
	int		status;

	close(main->pipe[WRITE_ENTRY]);
	main->read_entry = main->pipe[READ_ENTRY];
	pid = fork();
	if (pid == -1)
		ft_clean_exit(main, 1);
	if (!pid)
		end_command(main, idx);
	close(main->read_entry);
	waitpid(pid, &status, 0);
	ft_printf("%d\n", status);
	ft_clean_exit(main, status);
}

static void	kinder_garten(t_main *main)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (main->cmds[i] && main->cmds[i + 1])
	{
		close(main->pipe[WRITE_ENTRY]);
		main->read_entry = main->pipe[READ_ENTRY];
		if (pipe(main->pipe) == -1)
			ft_clean_exit(main, 1);
		pid = fork();
		if (pid == -1)
			ft_clean_exit(main, 1);
		if (!pid)
			middle_command(main, i);
		close(main->read_entry);
		i++;
	}
	last_cmds(main, i);
}

void	init_pipex(t_main *main)
{
	pid_t	pid;
	int		status;

	status = 0;
	if (pipe(main->pipe) == -1)
		ft_clean_exit(main, 1);
	pid = fork();
	if (pid == -1)
		ft_clean_exit(main, 1);
	if (!pid)
		first_command(main);
	kinder_garten(main);
}
