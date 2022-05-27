/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:09:50 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:09:51 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	define_param(int x, int y, t_superstruct *fractol)
{
	if (!fractol->num.freeze)
	{
		fractol->num.c_r = (x / (double)fractol->num.zoom) - fractol->num.xmax;
		fractol->num.c_i = (y / (double)fractol->num.zoom) - fractol->num.ymax;
		draw_julia(fractol);
	}
	return (0);
}

static void	init_complex(t_superstruct *fractol)
{
	fractol->num.z_r = (fractol->num.x / (double)fractol->num.zoom)
		+ fractol->num.xmin;
	fractol->num.z_i = (fractol->num.y / (double)fractol->num.zoom)
		+ fractol->num.ymin;
}

void	color_pixel_the_right_color(int i, t_superstruct *fractol)
{
	if (i == fractol->num.max_iteration)
		put_pixel_to_image(&(fractol->image),
			fractol->num.x, fractol->num.y, WHITE);
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

void	draw_julia(t_superstruct *fractol)
{
	int	i;

	i = 0;
	while (fractol->num.x < (int)(fractol->num.window_size_x))
	{
		while (fractol->num.y < (int)(fractol->num.window_size_y))
		{
			init_complex(fractol);
			while ((i < fractol->num.max_iteration)
				&& (module(fractol->num.z_r, fractol->num.z_i) < 4))
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
