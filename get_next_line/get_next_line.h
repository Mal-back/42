/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:58 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/18 22:29:05 by vlevy            ###   ########.fr       */
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
	char					content[BUFFER_SIZE + 1];
	struct s_list			*next;
}								t_list;

char		*get_next_line(int fd);
char		*read_till_eol(char *str, char *stash, t_list *lst, int fd);
void		ft_strncat(char *dest, char *src, int n);
char		*update_stash(char *stash, t_list  *tmp);
int			update_lst(t_list **lst, char *buff);
int			find_eol(char *buff);
char		*ft_lst_clear(t_list **lst);
int			ft_strlen_cs(char *str, char c);
char		*fill_str(char *stash, char *str, t_list *lst, int lst_size);
void 		ft_memset(char *str, int c, int n);
#endif
