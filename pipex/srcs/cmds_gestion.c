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

void	handle_command(t_main *main, int idx)
{
	if (idx != main->command_number - 1)
	{
		close(main->pipe[READ_ENTRY]);
		if (dup2(main->pipe[WRITE_ENTRY], STDOUT_FILENO) == -1)
			ft_clean_exit(main, DUP_ERROR);
		close(main->pipe[WRITE_ENTRY]);
	}
	if (idx != 0)
	{
		if (dup2(main->read_entry, STDIN_FILENO) == -1)
			ft_clean_exit(main, DUP_ERROR);
		close(main->read_entry);
	}
	assemble_command(main, idx);
	execve(main->cmds[idx][0], main->cmds[idx], main->envp);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(main->cmds[idx][0], 2);
	ft_clean_exit(main, EXECVE_ERROR);
}
