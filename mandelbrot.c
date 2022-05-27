/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:09:45 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:09:46 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_superstruct *fractol)
{
	fractol->num.c_r = (fractol->num.x / (float)fractol->num.zoom)
		+ fractol->num.xmin;
	fractol->num.c_i = (fractol->num.y / (float)fractol->num.zoom)
		+ fractol->num.ymin;
	fractol->num.z_r = 0;
	fractol->num.z_i = 0;
}

static void	color_pixel_the_right_color(int i, t_superstruct *fractol)
{
	if (i == fractol->num.max_iteration)
		put_pixel_to_image(&(fractol->image), fractol->num.x,
			fractol->num.y, BLACK);
	else
	{
		fractol->num.color = get_color(i, *fractol);
		put_pixel_to_image(&(fractol->image), fractol->num.x,
			fractol->num.y, fractol->num.color);
	}
}

static void	iterate_on_pixels(t_superstruct *fractol)
{
	fractol->num.tmp = fractol->num.z_r;
	fractol->num.z_r = (fractol->num.z_r * fractol->num.z_r)
		- (fractol->num.z_i * fractol->num.z_i) + fractol->num.c_r;
	fractol->num.z_i = (2 * fractol->num.tmp * fractol->num.z_i)
		+ fractol->num.c_i;
}

void	draw_mandelbrot(t_superstruct *fractol)
{
	int	i;

	i = 0;
	while (fractol->num.x < (int)(fractol->num.window_size_x))
	{
		while (fractol->num.y < (int)(fractol->num.window_size_y))
		{
			init_complex(fractol);
			while ((i < fractol->num.max_iteration)
				&& module(fractol->num.z_r, fractol->num.z_i) < 4)
			{
				iterate_on_pixels(fractol);
				i++;
			}
			color_pixel_the_right_color(i, fractol);
			fractol->num.y++;
			i = 0;
		}
		fractol->num.y = 0;
		fractol->num.x++;
	}
	fractol->num.x = 0;
	mlx_put_image_to_window(fractol->session.mlx, fractol->session.window,
		fractol->image.img, 0, 0);
}
