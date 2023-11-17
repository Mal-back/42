/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:27 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/17 18:11:43 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_eol(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*handle_eol(int lst_size, char *stash, t_list *lst)
{
	char		*str;
	t_list	*temp_node;
	int			i;
	
	last_node = lst_last(lst);
	i = 0;
	while(temp_node->content[i] != '\n' && temp_node->content[i])
		i++;
	str = malloc((stash + i + ((lst_size - 1) * BUFFER_SIZE) + 1)
	* sizeof (char));
	if (!str)
		return (ft_lst_clear(&lst));
	*str = 0;
	ft_strcat(str, stash);
	temp_node = lst;
	while (--lst_size)
	{
		ft_strcat(str, temp_node->content);
		temp_node = temp_node->next;
	}
	str = update_stash(temp_node, stash, str);
	ft_lst_clear(&lst);
	return (str);
}

char	*handle_eof(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	while (stash[i] != \n && stash[i])
		 i++;
	str = malloc((i + 1) * sizeof (char));
	if (!str)
		return (NULL);
	
}

char	*update_stash(t_list	*temp_node, char *stash, char *str)
{
	char	*tmp[BUFFER_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	while (temp_node->content[i] != '\n' && temp_node->content[i])
		{
			tmp[i] = temp_node->content[i];
			i++;
		}
	tmp[i] = temp_node->content[i];
	if (tmp[i] == '\n')
		tmp[i + 1] = 0;
	i++;
	ft_strcat(str, tmp);
	ft_strcat(stash, temp_node->content + i);
	return(str);
}

char *get_next_line(int fd)
{
	int							bytes_read;
	int							lst_size;
	char						buff[BUFFER_SIZE + 1];
	static char			*stash;
	t_list					*lst;
	
	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!find_eol(buff) && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_lst_clear(&lst));
		if (bytes_read == 0)
			return (handle_eof(&stash))
		buff[bytes_read] = 0;
		if (update_lst(&lst, buff, bytes_read))
			return (ft_lst_clear(&lst));
		lst_size++;
	}
	return (handle_eol(lst_size, buff, &stash, lst);
}
