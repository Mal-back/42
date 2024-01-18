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
# include <stdio.h>

# define READ_ENTRY 0
# define WRITE_ENTRY 1

// Error Code

typedef enum e_error
{
	BAD_INFILE_PERM = 0,
	BAD_OUTFILE_PERM = 1,
	FORK_ERROR = 2,
	PIPE_ERROR = 3,
	DUP_ERROR = 4,
	MALLOC = 5,
	INFILE_IS_DIR = 6,
	OUTFILE_IS_DIR = 7,
	NOT_ENOUGH_ARGUMENT = 8,
	EXECVE_ERROR = 127
}							t_error;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}							t_bool;
// Main struct, make possible to exit the program at any time

typedef struct s_main
{
	int		fd_infile;
	char	*infile;
	int		fd_outfile;
	char	*outfile;
	int		pipe[2];
	int		read_entry;
	t_bool	here_doc;
	int		command_number;
	char	**possible_paths;
	char	***cmds;
	char	*pwd;
	char	**envp;
}								t_main;

// check_functions
void	check_here_doc(t_main *main, int ac, char **av);
void	check_env(char **envp, t_main *main);
void	check_cmds(t_main *main, int ac, char **av);
void	check_files_and_dup(int ac, char **av, t_main *main);

void	init_pipex(t_main *main);
void	append_backslash(t_main *main);
void	assemble_command(t_main *main, int j);
void	handle_command(t_main *main, int idx);

void	ft_clean_exit(t_main *main, int code);
void	infile_error(t_main *main, int code);

#endif // !PIPEX_H
