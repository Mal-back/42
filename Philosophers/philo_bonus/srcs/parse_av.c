/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:35:07 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/19 15:35:08 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_is_space(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	return (0);
}

static int	ft_is_digit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

static int	ovf_check(char c, int res)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = res;
	while (res && i < 9)
	{
		tmp += res;
		if (res >= tmp)
			return (-1);
		i++;
	}
	tmp += c - 48;
	if (res >= tmp)
		return (-1);
	return (tmp);
}

static int	strong_atoi(char *str)
{
	int				res;
	int				i;
	int				j;

	i = 0;
	res = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	j = i;
	while (ft_is_digit(str[i]))
	{
		res = ovf_check(str[i], res);
		if (res == -1)
			return (res);
		i++;
	}
	if (i == j)
		return (-1);
	return (res);
}

void	parse_av(char **av, t_philo *philo)
{
	int	i;
	int	nb;

	i = 0;
	while (av[i])
	{
		nb = strong_atoi(av[i]);
		if (nb >= 0)
			philo->philo_info[i] = nb;
		else
			display_help(philo, 1);
		i++;
	}
}
