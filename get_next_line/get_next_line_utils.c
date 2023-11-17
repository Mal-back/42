/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:03:40 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/17 18:11:53 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int update_lst(t_list **lst, char *buff, int size)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof (t_list));
	if (!new)
	{
		ft_lst_clear(lst);
		return (1);
	}
	ft_strcat(new->content, buff);
	new->size = size;
	if(!*lst)
	{
		*lst = new;
		return (0);
	}

	tmp = *lst
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

char	*ft_lst_clear(t_list **lst)
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	while(*lst)
	{
		tmp = *lst->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	return (NULL);
}

t_list	*lst_last(lst);
{
	while(lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_strcat(char *dest, char *str)
{
	int	i;
	int	j;
	i = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return ;
}
