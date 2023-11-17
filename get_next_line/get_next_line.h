/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:58 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/17 15:27:19 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char					content[BUFF_SIZE + 1];
	int						size;
	struct s_list			*next;
}								t_list;

char	*get_next_line(int fd);
int		update_lst(t_list **lst, char *buff, int size);
int		find_eol(char *buff);
char	*ft_lst_clear(t_list **lst);


#endif
