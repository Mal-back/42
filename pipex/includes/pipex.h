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

// Error Code

# define BAD_INFILE_PERM 0
# define INFILE_IS_DIR 6
# define BAD_OUTFILE_PERM 1
# define OUTFILE_IS_DIR 7
# define FORK_ERROR 2
# define PIPE_ERROR 3
# define DUP_ERROR 4
# define MALLOC 5
# define EXECVE_ERROR 127

typedef struct s_main
{
	int		fd_infile;
	char	*infile;
	int		fd_outfile;
	char	*outfile;
	int		pipe[2];
	int		read_entry;
	int		command_number;
	char	**possible_paths;
	char	***cmds;
	char	*pwd;
	char	**envp;
}								t_main;

void	ft_clean_exit(t_main *main, int code);
void	infile_error(t_main *main, int code);
void	assemble_command(t_main *main, int j);
void	append_backslash(t_main *main);
void	init_pipex(t_main *main);

void	handle_command(t_main *main, int idx);
#endif // !PIPEX_H
