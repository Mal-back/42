/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:26:55 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/22 12:26:56 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

#define WIN_HEIGHT 1440
# define WIN_WIDTH  1440

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		relative_x_center;
	int		relative_y_center;
	double	slope_x;
	double	slope_y;
}							t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}								t_window;

typedef struct s_complex
{
	double	r;
	double	i;
}								t_complex;

void	my_pixel_put(t_image *img, int x, int y, unsigned int color);
void	handle_image(t_image *image, t_window *window);

#endif // !FRACTOL_OL_H
