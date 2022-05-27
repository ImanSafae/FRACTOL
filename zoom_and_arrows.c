/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:09:37 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:09:39 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	zoom_in(t_superstruct *fractol, t_coordinates pointer)
{
	double			scope_x;
	double			scope_y;

	if (fractol->num.zoom > 0)
	{
		fractol->num.zoom *= 1.5;
		scope_x = fractol->num.window_size_x / fractol->num.zoom;
		scope_y = fractol->num.window_size_y / fractol->num.zoom;
		fractol->num.xmin = pointer.x - (scope_x / 2);
		fractol->num.xmax = pointer.x + (scope_x / 2);
		fractol->num.ymin = pointer.y - (scope_y / 2);
		fractol->num.ymax = pointer.y + (scope_y / 2);
		fractol->num.max_iteration += 5;
		if (fractol->num.pattern == MANDELBROT)
			draw_mandelbrot(fractol);
		else if (fractol->num.pattern == JULIA)
			draw_julia(fractol);
	}
}

void	zoom_out(t_superstruct *fractol, t_coordinates pointer)
{
	double			scope_x;
	double			scope_y;

	if (fractol->num.zoom > 50)
	{
		fractol->num.zoom /= 1.5;
		scope_x = fractol->num.window_size_x / fractol->num.zoom;
		scope_y = fractol->num.window_size_y / fractol->num.zoom;
		fractol->num.xmin = pointer.x - (scope_x / 2);
		fractol->num.xmax = pointer.x + (scope_x / 2);
		fractol->num.ymin = pointer.y - (scope_y / 2);
		fractol->num.ymax = pointer.y + (scope_y / 2);
		fractol->num.max_iteration -= 5;
		if (fractol->num.pattern == MANDELBROT)
			draw_mandelbrot(fractol);
		else if (fractol->num.pattern == JULIA)
			draw_julia(fractol);
	}
}

int	handle_zoom(int mousecode, int x, int y, t_superstruct *fractol)
{
	t_coordinates	pointer;

	pointer.x = ((double)(x + 1) / fractol->num.zoom) + fractol->num.xmin;
	pointer.y = ((double)(y + 1) / fractol->num.zoom) + fractol->num.ymin;
	if (mousecode == 5)
		zoom_in(fractol, pointer);
	else if (mousecode == 4)
	{
		if (fractol->num.zoom > 0)
			zoom_out(fractol, pointer);
	}
	return (0);
}

void	arrow_movements(int keycode, t_superstruct *fractol)
{
	if (keycode == 124)
	{
		fractol->num.xmax += (200.0 / (fractol->num.zoom + 50));
		fractol->num.xmin += (200.0 / (fractol->num.zoom + 50));
	}
	if (keycode == 126)
	{
		fractol->num.ymax -= (200.0 / (fractol->num.zoom + 50));
		fractol->num.ymin -= (200.0 / (fractol->num.zoom + 50));
	}
	if (keycode == 125)
	{
		fractol->num.ymax += (200.0 / (fractol->num.zoom + 50));
		fractol->num.ymin += (200.0 / (fractol->num.zoom + 50));
	}
	if (keycode == 123)
	{
		fractol->num.xmax -= (200.0 / (fractol->num.zoom + 50));
		fractol->num.xmin -= (200.0 / (fractol->num.zoom + 50));
	}
}

int	key_handle(int keycode, t_superstruct *fractol)
{
	arrow_movements(keycode, fractol);
	if (keycode == 53)
	{
		mlx_destroy_window(fractol->session.mlx, fractol->session.window);
		exit(EXIT_SUCCESS);
	}
	if ((keycode == 49) && (fractol->num.pattern == JULIA))
	{
		if (!fractol->num.freeze)
			fractol->num.freeze = 1;
		else
			fractol->num.freeze = 0;
	}
	if (fractol->num.pattern == MANDELBROT)
		draw_mandelbrot(fractol);
	else if (fractol->num.pattern == JULIA)
		draw_julia(fractol);
	return (0);
}
