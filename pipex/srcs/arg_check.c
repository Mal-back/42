/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:39:10 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/17 17:39:12 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_outfile(t_main *main, int ac, char **av)
{
	if (main->here_doc == FALSE)
	{
		main->fd_outfile = open(av[ac - 1],
				O_RDWR | O_CREAT | O_TRUNC, 00244 | 00400);
	}
	else
	{
		main->fd_outfile = open(av[ac - 1],
				O_RDWR | O_CREAT | O_APPEND, 00244 | 00400);
	}
	if (main->fd_outfile == -1)
	{
		if (errno == EISDIR)
			ft_clean_exit(main, OUTFILE_IS_DIR);
		ft_clean_exit(main, BAD_OUTFILE_PERM);
	}
}

void	check_files_and_dup(int ac, char **av, t_main *main)
{
	main->infile = av[1];
	main->outfile = av[ac - 1];
	if (main->here_doc == FALSE)
	{
		main->fd_infile = open(av[1], O_RDONLY);
		if (main->fd_infile == -1)
			infile_error(main, BAD_INFILE_PERM);
	}
	if (dup2(main->fd_infile, STDIN_FILENO) == -1)
		infile_error(main, BAD_INFILE_PERM);
	open_outfile(main, ac, av);
	if (dup2(main->fd_outfile, STDOUT_FILENO) == -1)
		ft_clean_exit(main, BAD_OUTFILE_PERM);
	close(main->fd_infile);
	close(main->fd_outfile);
}

void	check_cmds(t_main *main, int ac, char **av)
{
	int	i;

	i = 0;
	main->cmds = malloc((ac - (2 + main->here_doc)) * sizeof (char **));
	if (!main->cmds)
		ft_clean_exit(main, MALLOC);
	main->cmds[ac - (3 + main->here_doc)] = NULL;
	main->command_number = ac - (3 + main->here_doc);
	while (i < ac - (3 + (int)main->here_doc))
	{
		main->cmds[i] = ft_split(av[i + (2 + main->here_doc)], ' ');
		if (!main->cmds[i])
			ft_clean_exit(main, MALLOC);
		i++;
	}
}

void	check_env(char **envp, t_main *main)
{
	int		i;

	i = 0;
	if (!envp || !*envp)
		return ;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	if (!envp[i])
		return ;
	main->pwd = ft_strdup(envp[i] + 4);
	if (!main->pwd)
		ft_clean_exit(main, MALLOC);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return ;
	main->possible_paths = ft_split(envp[i] + 5, ':');
	if (!main->possible_paths)
		ft_clean_exit(main, MALLOC);
	append_backslash(main);
}
