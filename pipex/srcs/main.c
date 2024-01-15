/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:11:29 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/11 17:11:29 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static	void	init_struct(t_main *main)
{
	main->fd_infile = -1;
	main->fd_outfile = -1;
	main->cmds = NULL;
	main->possible_paths = NULL;
	main->pwd = NULL;
	main->read_entry = -1;
}

static	void	check_files_and_dup(int ac, char **av, t_main *main)
{
	main->fd_infile = open(av[1], O_RDONLY);
	if (main->fd_infile == -1 || errno == EISDIR)
		ft_printf("Error on fd1\n");
	main->fd_outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 00244 | 00400);
	if (main->fd_outfile == -1)
	{
		perror("Error while opening :");
		ft_clean_exit(main, 1);
	}
	if (dup2(main->fd_infile, STDIN_FILENO) == -1)
		ft_clean_exit(main, 1);
	if (dup2(main->fd_outfile, STDOUT_FILENO) == -1)
		ft_clean_exit(main, 1);
	close(main->fd_infile);
	close(main->fd_outfile);
}

static void	check_cmds(t_main *main, int ac, char **av)
{
	int	i;

	i = 0;
	main->cmds = malloc((ac - 2) * sizeof (char **));
	if (!main->cmds)
		ft_clean_exit(main, 1);
	main->cmds[ac - 3] = NULL;
	while (i < ac - 3)
	{
		main->cmds[i] = ft_split(av[i + 2], ' ');
		if (!main->cmds[i])
			ft_clean_exit(main, 1);
		i++;
	}
}

static void	check_env(char **envp, t_main *main)
{
	int		i;

	i = 0;
	if (!envp || !*envp)
		ft_clean_exit(main, 1);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		ft_clean_exit(main, 1);
	main->possible_paths = ft_split(envp[i] + 5, ':');
	if (!main->possible_paths)
		ft_clean_exit(main, 1);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	if (!envp[i])
		ft_clean_exit(main, 1);
	main->pwd = ft_strdup(envp[i] + 4);
	if (!main->pwd)
		ft_clean_exit(main, 1);
	append_backslash(main);
}

int	main(int ac, char **av, char **envp)
{
	t_main	main;

	if (ac < 5)
		exit(EXIT_FAILURE);
	main.envp = envp;
	init_struct(&main);
	check_files_and_dup(ac, av, &main);
	check_env(envp, &main);
	check_cmds(&main, ac, av);
	init_pipex(&main);
	ft_clean_exit(&main, 0);
}
