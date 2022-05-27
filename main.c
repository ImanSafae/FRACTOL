/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:10:05 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:10:06 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_numbers	init_struct(t_numbers *num)
{
	num->x = 0;
	num->y = 0;
	num->zoom = 200;
	num->xmin = -2.0;
	num->xmax = 2.0;
	num->ymin = -2.0;
	num->ymax = 2.0;
	num->freeze = 0;
	num->window_size_x = ((num->xmax - num->xmin) * num->zoom);
	num->window_size_y = ((num->ymax - num->ymin) * num->zoom);
	return (*num);
}

static void	draw_fractal(t_superstruct *fractol, t_numbers *num, t_vars *sesh)
{
	if (num->pattern == MANDELBROT)
		draw_mandelbrot(fractol);
	else if (num->pattern == JULIA)
	{
		draw_julia(fractol);
		mlx_hook(sesh->window, 6, 0, define_param, fractol);
	}
}

int	main(int argc, char **argv)
{
	t_vars					session;
	t_imagedata				image;
	t_colors				colors;
	t_numbers				num;
	t_superstruct			fractol;

	manage_errors(argc, argv, &num);
	colors = init_colors(&colors, argc, argv);
	num = init_struct(&num);
	session.mlx = mlx_init();
	session.window = mlx_new_window(session.mlx, (int)(num.window_size_x),
			(int)(num.window_size_y), argv[1]);
	image.img = mlx_new_image(session.mlx, (int)(num.window_size_x),
			(int)(num.window_size_y));
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	fractol.session = session;
	fractol.image = image;
	fractol.num = num;
	fractol.colors = colors;
	draw_fractal(&fractol, &num, &session);
	send_instructions();
	mlx_mouse_hook(session.window, handle_zoom, &fractol);
	mlx_key_hook(session.window, key_handle, &fractol);
	mlx_loop(session.mlx);
}
