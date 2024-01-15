/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:23:01 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/11 17:23:02 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft.h"

# define READ_ENTRY 0
# define WRITE_ENTRY 1

typedef struct s_main
{
	int		fd_infile;
	int		fd_outfile;
	int		pipe[2];
	int		read_entry;
	char	**possible_paths;
	char	***cmds;
	char	*pwd;
	char	**envp;
}								t_main;

void	ft_clean_exit(t_main *main, int code);
void	assemble_command(t_main *main, int j);
void	append_backslash(t_main *main);
void	init_pipex(t_main *main);

// Handling commands

void	first_command(t_main *main);
void	middle_command(t_main *main, int idx);
void	end_command(t_main *main, int idx);
#endif // !PIPEX_H
