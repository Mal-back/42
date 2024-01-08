/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:18:04 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/06 19:18:05 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	parse_line(char *line)
{
	int	color_value;
	int	i;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
		i++;
	if (!(ft_isdigit(line[i])) || i != 4)
		return (-1);
	color_value = ft_atoi(line + i);
	if (color_value < 0 || color_value > 255)
		return (-2);
	return (color_value);
}

static int	get_color(unsigned char *colorshade, char *line, int fd)
{
	int	color_value;
	int	ret_val;

	ret_val = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	color_value = parse_line(line);
	if (color_value < 0)
		ret_val = color_value;
	else
		*colorshade = color_value;
	free(line);
	return (ret_val);
}

static int	parse_config(t_color *colormap, int fd, char *str)
{
	char	*line;
	int		error_tag;
	int		i;

	i = 0;
	while (i < 7)
	{
		error_tag = get_color(&colormap[i].red, line, fd);
		if (error_tag < 0)
			return (print_parsing_error(error_tag, i, 0, str), 0);
		error_tag = get_color(&colormap[i].green, line, fd);
		if (error_tag < 0)
			return (print_parsing_error(error_tag, i, 1, str), 0);
		error_tag = get_color(&colormap[i].blue, line, fd);
		if (error_tag < 0)
			return (print_parsing_error(error_tag, i, 2, str), 0);
		line = get_next_line(fd);
		if (line)
			free (line);
		i++;
	}
	return (1);
}

static int	open_shade_config(char *str, t_color *colormap)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Can't open the file at this path : ", 2);
		ft_putendl_fd(str, 2);
		return (0);
	}
	while (i++ < 14)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
	}
	if (!parse_config(colormap, fd, str))
	{
		close (fd);
		return (0);
	}
	close(fd);
	return (1);
}

void	init_color(t_main *main)
{
	if (!open_shade_config("ressources/shade1.c", main->image->colormap[0]))
		kill(main, 1);
	if (!open_shade_config("ressources/shade2.c", main->image->colormap[1]))
		kill(main, 1);
	if (!open_shade_config("ressources/shade3.c", main->image->colormap[2]))
		kill(main, 1);
	if (!open_shade_config("ressources/shade4.c", main->image->colormap[3]))
		kill(main, 1);
}
