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

#include "pipex.h"

static	void	init_struct(t_main *main)
{
	main->fd_infile = -1;
	main->fd_outfile = -1;
	main->cmds = NULL;
	main->possible_paths = NULL;
	main->pwd = NULL;
	main->read_entry = -1;
	main->here_doc = FALSE;
}

int	main(int ac, char **av, char **envp)
{
	t_main	main;

	main.envp = envp;
	init_struct(&main);
	if (ac < 5 || (main.here_doc == TRUE && ac < 6))
		ft_clean_exit(&main, NOT_ENOUGH_ARGUMENT);
	check_here_doc(&main, ac, av);
	check_env(envp, &main);
	check_cmds(&main, ac, av);
	check_files_and_dup(ac, av, &main);
	init_pipex(&main);
	ft_clean_exit(&main, 0);
}
