/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:45 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 14:35:43 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# include <unistd.h>

# define FT_H

void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mul(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
int ft_find_op(char c, int b);
void  ft_print_error(int a);

#endif
