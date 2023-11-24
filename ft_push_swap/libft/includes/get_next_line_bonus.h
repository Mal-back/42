/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:58 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/22 17:09:22 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_CAP
#  define FD_CAP 1024
# endif

typedef struct s_list
{
	char					*content;
	struct s_list			*next;
}								t_list;

char		*get_next_line(int fd);
char		*read_till_eol(char *str, char *stash, t_list *lst, int fd);
void		ft_strncat(char *dest, char *src, int n);
char		*update_stash(char *stash, t_list *tmp);
int			update_lst(t_list **lst, char *buff);
int			find_eol(char *buff);
char		*ft_lst_clear(t_list **lst);
int			ft_strlen_cs(char *str, char c, int f);
char		*fill_str(char *stash, char *str, t_list *lst, int lst_size);
void		ft_memset(char *str, int c, int n);
#endif
