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
#include <stdio.h>

static	void	init_struct(t_main *main)
{
	main->fd1 = -1;
	main->fd2 = -1;
	main->cmds = NULL;
	main->possible_paths = NULL;
}

static	void	check_files(int ac, char **av, t_main *main)
{
	main->fd1 = open(av[1], O_RDONLY);
	if (main->fd1 == -1 || errno == EISDIR)
		ft_printf("Error on fd1\n");
	main->fd2 = open(av[ac - 1], O_RDWR | O_CREAT);
	if (main->fd2 == -1)
	{
		perror("Error while opening :");
		ft_clean_exit(main, 1);
	}
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
	char	*joined_str;

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
	while (main->possible_paths[i])
	{
		joined_str = ft_strjoin(main->possible_paths[i], "/");
		if (!joined_str)
			ft_clean_exit(main, 1);
		free (main->possible_paths[i]);
		main->possible_paths[i] = joined_str;
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_main	main;

	if (ac < 5)
	{
		ft_putendl_fd("Not enough argument", 2);
		exit(EXIT_FAILURE);
	}
	init_struct(&main);
	check_files(ac, av, &main);
	check_env(envp, &main);
	ft_clean_exit(&main, 0);
}
