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

void	ft_clean_exit(t_main *main, int code)
{
	close(main->fd1);
	close(main->fd2);
	if (main->possible_paths)
		ft_free_tab(main->possible_paths);
	if (main->cmds)
		ft_free_tab(main->cmds);
	ft_printf("Coucou\n");
	exit (code);
}
