/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:28:06 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/27 14:28:08 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_imagedata {
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imagedata;

typedef struct s_coordinates {
	double	x;
	double	y;
}				t_coordinates;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}				t_vars;

typedef struct s_numbers {
	int		pattern;
	int		x;
	int		y;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	tmp;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		zoom;
	double	window_size_x;
	double	window_size_y;
	int		color;
	int		max_iteration;
	int		freeze;
}				t_numbers;

typedef struct s_colors {
	int	color1;
	int	color2;
	int	color3;
	int	color4;
	int	color5;
	int	color6;
	int	color7;
	int	color8;
	int	color9;
	int	color10;
	int	divider;
}				t_colors;

typedef struct s_superstruct {
	t_vars		session;
	t_imagedata	image;
	t_numbers	num;
	t_colors	colors;
}				t_superstruct;

//patterns
# define MANDELBROT 1
# define JULIA 2

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

// iridescent palette
# define LAVENDER 0x00c4b4f6
# define BABY_BLUE 0x00b0d4ea
# define PISTACHIO 0x00bfeecf
# define PINK 0x00FDBFE5
# define CREAM 0x00fdfaf7

// psychedelic palette
# define SKY_BLUE 0x0075D5FD
# define BLUE 0x004CBEFF
# define PERIWINKLE 0x00729DFF
# define PURPLE 0x00B76CFD
# define FUSCHIA 0x00EE42C2
# define MAGENTA 0x00FF2281
# define BRIGHT_PINK 0x00FF01D7
# define DARK_PURPLE 0x00B800EB
# define ROYAL_BLUE 0x00011FFD
# define TURQUOISE 0x0000EDF5

//pastel palette
# define CLASSIC_ROSE 0x00FFCFE5
# define MIMI_PINK 0x00FDDFEC
# define LAVENDER_BLUSH 0x00FFF5F7
# define MAGNOLIA 0x00F4EDFF
# define PALE_LAVENDER 0x00EBD6FF
# define MILD_LAVENDER 0x00E6C8FD

//teal palette
# define TEAL 0x00008080
# define JUNGLE 0x00239895
# define VERDIGRIS 0x0047B0AA
# define AQUAMARINE 0x006AC9BE
# define EGG_BLUE 0x008EE1D3
# define PALE_BLUE 0x00B1F9E8

//biscuit palette
# define MAX_PURPLE 0x007F2A87
# define CRAYOLA 0x00B24993
# define QUARTZ 0x00C45A91
# define VIOLET 0x00DC6F93
# define SALMON 0x00F99D9E
# define SAND 0x00E3D5A0

// lys palette
// # define CHAMPAGNE 0x00F7E8CA
# define APRICOT 0x00FDCDB6
# define PEACH 0x00F9C0BC
# define LIGHTPINK 0x00F5B0C3
# define PEARL 0x00DFADD2
# define TROPICAL 0x00C1AEDA
# define PERI 0x00C5CAED

void			arrow_movements(int keycode, t_superstruct *fractol);
int				create_trgb(int t, int r, int g, int b);
int				define_param(int x, int y, t_superstruct *fractol);
int				default_colors(int i, t_superstruct fractol);
void			draw_julia(t_superstruct *fractol);
void			draw_mandelbrot(t_superstruct *fractol);
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, int n);
void			ft_putstr_fd(char *s, int fd);
int				get_color(int i, t_superstruct fractol);
int				get_offset(t_imagedata image, int x, int y);
int				handle_zoom(int mousecode, int x,
					int y, t_superstruct *fractol);
int				key_handle(int keycode, t_superstruct *fractol);
void			manage_errors(int argc, char **argv, t_numbers *num);
double			module(double x, double y);
void			put_pixel_to_image(t_imagedata *image, int x, int y, int color);
void			send_instructions(void);
void			zoom_in(t_superstruct *fractol, t_coordinates pointer);
void			zoom_out(t_superstruct *fractol, t_coordinates pointer);
t_colors		biscuit_palette(t_colors *colors);
t_colors		default_palette(t_colors *colors);
t_colors		iridescent_palette(t_colors *colors);
t_colors		lys_palette(t_colors *colors);
t_colors		pastel_palette(t_colors *colors);
t_colors		teal_palette(t_colors *colors);
char			*uncapitalize(char *str);
t_colors		init_colors(t_colors *colors, int argc, char **argv);
t_numbers		init_struct(t_numbers *num);

#endif
