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
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define WIN_HEIGHT 1200
# define WIN_WIDTH  1200
# define BUTTON_HEIGHT 25
# define BUTTON_WIDTH 80
# define BUTTON_1 "ressources/Shade1Button.xpm "
# define BUTTON_2 "ressources/Shade2Button.xpm "
# define BUTTON_3 "ressources/Shade3Button.xpm "
# define BUTTON_4 "ressources/Shade4Button.xpm "
# define BUTTON_5 "ressources/ShadeMixedButton.xpm "

typedef enum e_fractal
{
	MANDELBROT = 0,
	JULIA = 1,
	BOUDHABROT = 2
}							t_fractal;

typedef enum e_color_palette
{
	BLUE = 0,
	PURPLE = 1,
	RED = 2,
	RAINBOW = 3
}							t_color_palette;

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

typedef struct s_complex
{
	double	r;
	double	i;
}								t_complex;

typedef struct s_button
{
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}								t_button;

typedef struct s_image
{
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				max_iter;
	int				command_display;
	double			slope_x;
	double			slope_y;
	double			x_origin;
	double			y_origin;
	t_complex		c;
	t_fractal		fractal;
	t_color			colormap[4][7];
	t_color_palette	color;
	double			zoom;
	int				zoom_tracker;
	int				refresh;
	int				rand_color;
}							t_image;

typedef void	(*t_function)(t_image *, int, int);

typedef struct s_main
{
	t_image		*image;
	t_window	*window;
	t_button	button[5];
	t_function	compute[3];
}							t_main;

void	my_pixel_put(t_image *img, int x, int y, unsigned int color);
void	init_window(t_main *main);
void	init_color(t_main *main);
void	init_button(t_main *main);
void	handle_image(t_main *main);
void	compute_mandelbrot(t_image *image, int x, int y);
void	compute_julia(t_image *image, int x, int y);
void	set_relative_center_and_slope(t_image *image);
void	ft_blur(t_image *image);
int		def_color(int idx, double z, int max_iter, t_color *colortab);
int		colormap(int t, int r, int g, int b);
int		handle_key(int key, t_main *param);
int		handle_mouse(int key, int x, int y, t_main *param);
char	retrieve_color(t_image *img, int x, int y, int i);
void	free_struct(t_main *main);
void	display_help(char **tab, t_main *main);
int		invalid_number(char *str);
int		kill(t_main *param, int code);
int		kill_cross(t_main *param);
void	map(t_image *image, t_complex *complex, int x, int y);
void	set_relative_center_and_slope(t_image *image);
double	is_in_plan(t_complex *nbr);
void	round_for_smoothing(t_complex *nbr, t_complex c);
void	print_parsing_error(int error_tag, int i, int j, char *str);
void	ft_display_command(t_main *main);

#endif // !FRACTOL_OL_H
