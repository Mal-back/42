/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:40 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/19 19:03:57 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	update_lst(t_list **lst, char *buff)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof (t_list));
	if (!new)
		return (1);
	new->content = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (new->content == NULL)
	{
		free(new);
		return (1);
	}
	ft_memset(new->content, 0, BUFFER_SIZE);
	ft_strncat(new->content, buff, BUFFER_SIZE + 1);
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

char	*ft_lst_clear(t_list **lst)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *lst;
	if (!lst)
		return (NULL);
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr->content);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
	return (NULL);
}

void	ft_strncat(char *dest, char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i] && i < n - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (i < n)
	{
		dest[j] = 0;
		i++;
		j++;
	}
	return ;
}

int	ft_strlen_cs(char *str, char c, int f)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (f && str[i] == c)
		i++;
	return (i);
}

void	ft_memset(char *str, int c, int n)
{
	while (n)
	{
		*str++ = c;
		n--;
	}
	return ;
}
