/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:53:15 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/17 14:53:16 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <unistd.h>

static void	ctrl_d_warning(char *limiter, int idx)
{
	ft_putstr_fd("pipex: warning: here-document at line ", 2);
	ft_putnbr_fd(idx + 1, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(limiter, 2);
	ft_putendl_fd("')", 2);
}

static void	read_stdin(t_main *main, char *limiter, char *line)
{
	int		i;

	i = 0;
	line = NULL;
	while ((line != NULL || !i))
	{
		line = get_next_line(STDIN_FILENO);
		if (line && ft_strncmp(line, limiter, ft_strlen(line)))
		{
			write(main->fd_infile, line, ft_strlen(line));
			if (line)
				free(line);
		}
		else
		{
			if (!line)
				ctrl_d_warning(limiter, i);
			else
			{
				free(line);
				line = NULL;
			}
		}
		i++;
	}
}

static char	*get_good_limiter(t_main *main, char *limiter)
{
	char *full_limiter;

	full_limiter = ft_strjoin(limiter, "\n");
	if (!full_limiter)
		ft_clean_exit(main, MALLOC);
	limiter = full_limiter;
	return (limiter);
}

void	check_here_doc(t_main *main, int ac, char **av)
{
	char	*limiter;
	char	*line;

	line = NULL;
	if (ft_strncmp(av[1], "here_doc", 9))
		return ;
	if (ac < 6)
		ft_clean_exit(main, NOT_ENOUGH_ARGUMENT);
	main->here_doc = TRUE;
	limiter = get_good_limiter(main, av[2]);
	main->fd_infile = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	read_stdin(main, limiter, line);
	close(main->fd_infile);
	main->fd_infile = open(".here_doc", O_RDONLY);
	free(limiter);
}
