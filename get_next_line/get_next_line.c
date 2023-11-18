/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:27 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/18 23:11:50 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *fill_str(char *stash, char *str, t_list *lst, int lst_size)
{
	t_list	*temp_node;
	int			len;

	len = ft_strlen_cs(stash, '\n');
	ft_strncat(str, stash, len + 1);
	if (lst != NULL)
	{
		temp_node = lst;
		while(--lst_size)
		{
			ft_strncat(str, temp_node->content, BUFFER_SIZE + 1);
			temp_node = temp_node->next;
		}
		len = ft_strlen_cs(temp_node->content, '\n');
		if (*(temp_node->content + len) == '\n')
			len++;
		ft_strncat(str, temp_node->content, len + 1);
	}
	return (str);
}

char	*update_stash(char *stash, t_list *temp_str_node)
{
	char temp_str[BUFFER_SIZE + 1];
	int	len_to_trim;
	
	if (temp_str_node != NULL)
	{
		ft_memset(stash, 0, BUFFER_SIZE + 1);
		len_to_trim = ft_strlen_cs(temp_str_node->content, '\n');
		if (*(temp_str_node->content + len_to_trim) == '\n')
			len_to_trim++;
		ft_strncat(stash, temp_str_node->content + len_to_trim + 1, (BUFFER_SIZE
		- len_to_trim + 1));
	}
	else
	{
		ft_memset(temp_str, 0, BUFFER_SIZE + 1);
		len_to_trim = ft_strlen_cs(stash, '\n');
		//if (*(stash + len_to_trim) == '\n')
		//	len_to_trim++;
		ft_strncat(temp_str, stash + len_to_trim, BUFFER_SIZE - len_to_trim + 1);
		ft_memset(stash, 0, BUFFER_SIZE + 1);
		ft_strncat(stash, temp_str, BUFFER_SIZE + 1);
	}
	return (stash);
}

char	*handle_eol(int lst_size, char *stash, t_list *lst)
{
	t_list	*tmp;
	char		*str;
	int			i;
	int			len;

	i = 0;
	tmp = lst;
	if (tmp != NULL)
	{
		while(tmp->next)
			tmp = tmp->next;
		i = ft_strlen_cs(tmp->content, '\n');
	}
	else
		lst_size = 1;
	len = ft_strlen_cs(stash, '\n') + i + ((lst_size - 1) * BUFFER_SIZE);
	str = malloc((len + 1) * sizeof (char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, len + 1);
	str = fill_str(stash, str, lst, lst_size);
	stash = update_stash(stash, tmp);
	ft_lst_clear(&lst);
	return (str);
}

char	*read_till_eol(char *str, char *stash, t_list *lst, int fd)
{
	int		lst_size;
	int		bytes_read;
	char	buff[BUFFER_SIZE + 1];

	lst_size = 0;
	ft_memset(buff, 66, BUFFER_SIZE);
	bytes_read = BUFFER_SIZE;
	while (ft_strlen_cs(buff, '\n') == BUFFER_SIZE && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_lst_clear(&lst));
		if (bytes_read == 0)
			return (handle_eol(lst_size, stash, lst));
		buff[bytes_read] = 0;
		if (update_lst(&lst, buff))
			return (ft_lst_clear(&lst));
		lst_size++;
	}
	str = handle_eol(lst_size, stash, lst);
	return (str);
}

char *get_next_line(int fd)
{
	char						*str;
	static char			stash[BUFFER_SIZE + 1];
	t_list					*lst;
	int							stash_len;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	lst = NULL;
	stash_len = ft_strlen_cs(stash, '\n');
	if (*stash + stash_len  == '\n')
		str = handle_eol(1, stash, lst);
	else
		str = read_till_eol(str, stash, lst, fd);
	if (*stash == 0 && *str == 0)
		str = NULL;
	return (str);
}
