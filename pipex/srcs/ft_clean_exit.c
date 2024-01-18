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

static void	free_all(t_main *main)
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
	if (main->here_doc == TRUE)
		unlink(".here_doc");
}

static void	ft_error_next(t_main *main, int code)
{
	if (code == DUP_ERROR)
		perror("Dup error : ");
	else if (code == BAD_OUTFILE_PERM)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putendl_fd(main->outfile, 2);
	}
	else if (code == OUTFILE_IS_DIR)
	{
		ft_putstr_fd("pipex: is a directory: ", 2);
		ft_putendl_fd(main->outfile, 2);
		code = 1;
	}
}

void	ft_clean_exit(t_main *main, int code)
{
	if (code == MALLOC)
		perror("Malloc error ");
	else if (code == PIPE_ERROR)
		perror("Pipe error ");
	else if (code == FORK_ERROR)
		perror("Fork error ");
	else if (code == NOT_ENOUGH_ARGUMENT)
	{
		ft_putendl_fd("Usage without here_doc : \"./pipex infile cmd1 cmd2 \
... cmdn outfile\"", 2);
		ft_putendl_fd("Usage with heredoc : \"./pipex here_doc LIMITER \
cmd1 cmd 2 ... cmdn outfile\"", 2);
	}
	else
		ft_error_next(main, code);
	free_all(main);
	exit (code);
}

void	infile_error(t_main *main, int code)
{
	if (code == BAD_INFILE_PERM)
	{
		ft_putstr_fd(main->cmds[0][0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(main->infile, 2);
		ft_putendl_fd(": Permission denied.", 2);
		main->fd_infile = open("/dev/null", O_RDONLY);
	}
	else if (code == INFILE_IS_DIR)
	{
		ft_putstr_fd(main->cmds[0][0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(main->infile, 2);
		ft_putendl_fd(": Is a directory.", 2);
		main->fd_infile = open("/dev/null", O_RDONLY);
	}
}
