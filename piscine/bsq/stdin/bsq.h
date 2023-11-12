/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:06:59 by aattali           #+#    #+#             */
/*   Updated: 2023/07/19 17:27:57 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 1073741824

typedef struct s_map {
	int		length;
	int		len;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}	t_map;

typedef struct s_success {
	int	lin;
	int	col;
	int	size;
}	t_success;

typedef struct s_tested {
	int	width;
	int	height;
}	t_tested;

int		ft_error(int type);
int		ft_strlen(char *s);
int		ft_verify(char *map, int *len);
int		ft_solve(t_map *map);
int		ft_atoi(char *str, int stop);
void	ft_driver(char **maps);
void	ft_print(t_map *map);
void	ft_free2(char **arr);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *str, char *charset);
char	**ft_split2(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);
void	search_square_ception(t_map *map, t_tested *tested, int *width,
			int *last_o);
char  *ft_strcat(char *dest, char *src);

#endif
