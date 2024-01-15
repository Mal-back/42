/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_gestion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:10:31 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/15 16:10:32 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	first_command(t_main *main)
{
	close(main->pipe[READ_ENTRY]);
	if (dup2(main->pipe[WRITE_ENTRY], STDOUT_FILENO) == -1)
		ft_clean_exit(main, 1);
	close(main->pipe[WRITE_ENTRY]);
	assemble_command(main, 0);
	execve(main->cmds[0][0], main->cmds[0], main->envp);
}

void	middle_command(t_main *main, int idx)
{
	close(main->pipe[READ_ENTRY]);
	if (dup2(main->read_entry, STDIN_FILENO) == -1)
		ft_clean_exit(main, 1);
	close(main->read_entry);
	if (dup2(main->pipe[WRITE_ENTRY], STDOUT_FILENO) == -1)
		ft_clean_exit(main, 1);
	close(main->pipe[WRITE_ENTRY]);
	assemble_command(main, idx);
	execve(main->cmds[idx][0], main->cmds[idx], main->envp);
}

void	end_command(t_main *main, int idx)
{
	if (dup2(main->read_entry, STDIN_FILENO) == -1)
		ft_clean_exit(main, 1);
	close(main->read_entry);
	assemble_command(main, idx);
	execve(main->cmds[idx][0], main->cmds[idx], main->envp);
}
