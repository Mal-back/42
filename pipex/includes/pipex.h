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
# include <errno.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_main
{
	int		fd1;
	int		fd2;
	char	**possible_paths;
	char	***cmds;
}								t_main;

void	ft_clean_exit(t_main *main, int code);

#endif // !PIPEX_H
