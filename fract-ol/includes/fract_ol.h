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
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define WIN_HEIGHT 800
# define WIN_WIDTH  800
# define ESCAPE_LOG 0.30102999566
# define LIGHT 0.61
# define SATURATION 1

typedef enum e_fractal
{
	MANDELBROT = 0,
	JULIA = 1,
	BOUDHABROT = 2
}							t_fractal;

typedef enum e_color_palette
{
	BLUE = 0,
	GREEN = 1,
	RED = 2,
	RAINBOW = 3,
	PSYCHEDELIC = 4
}							t_color_palette;

typedef struct s_specifications
{
	t_fractal		fractal;
	t_color_palette	palette;
	double			cx;
	double			cy;
}								t_specifications;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}								t_window;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}								t_color;

typedef struct s_smoothing
{
	int		color1;
	int		color2;
	double	reminder_1;
	double	reminder_2;
}							t_smoothing;

typedef struct s_image
{
	t_window	*open_win;
	void		*image;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			max_iter;
	double		slope_x;
	double		slope_y;
	double		x_origin;
	double		y_origin;
	double		zoom;
	int			zoom_tracker;
}							t_image;

typedef struct s_complex
{
	double	r;
	double	i;
}								t_complex;

void	my_pixel_put(t_image *img, int x, int y, unsigned int color);
void	handle_image(t_image *image, t_window *window);
void	set_relative_center_and_slope(t_image *image);
void	ft_blur(t_image *image);
int		def_color(int idx, double z, int max_iter);
int		colormap(int t, int r, int g, int b);
char	retrieve_color(t_image *img, int x, int y, int i);

#endif // !FRACTOL_OL_H
