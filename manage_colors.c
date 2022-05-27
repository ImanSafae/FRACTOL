/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:55:17 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:55:18 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	default_colors(int i, t_superstruct fractol)
{
	int	color;
	int	divider;
	int	iter;

	divider = fractol.colors.divider;
	iter = fractol.num.max_iteration;
	if (i >= (6 * (iter / divider)) && i < (7 * (iter / divider)))
		color = fractol.colors.color7;
	else if (i >= (7 * (iter / divider)) && i < (8 * (iter / divider)))
		color = fractol.colors.color8;
	else if ((i >= 8 * (iter / divider)) && i < (9 * (iter / divider)))
		color = fractol.colors.color9;
	else
		color = fractol.colors.color10;
	return (color);
}

int	get_color(int i, t_superstruct fractol)
{
	int	color;
	int	divider;
	int	iter;

	divider = fractol.colors.divider;
	iter = fractol.num.max_iteration;
	if (i < (iter / divider))
		color = fractol.colors.color1;
	else if ((i >= (iter / divider)) && (i < 2 * (iter / divider)))
		color = fractol.colors.color2;
	else if ((i >= 2 * (iter / divider)) && i < (3 * (iter / divider)))
		color = fractol.colors.color3;
	else if (i >= (3 * (iter / divider)) && i < (4 * (iter / divider)))
		color = fractol.colors.color4;
	else if (i >= (4 * (iter / divider)) && i < (5 * (iter / divider)))
		color = fractol.colors.color5;
	else if (i >= (5 * (iter / divider)) && i < (6 * (iter / divider)))
		color = fractol.colors.color6;
	if (divider == 10)
		color = default_colors(i, fractol);
	return (color);
}

t_colors	default_palette(t_colors *colors)
{
	colors->divider = 10;
	colors->color1 = SKY_BLUE;
	colors->color2 = BLUE;
	colors->color3 = PERIWINKLE;
	colors->color4 = PURPLE;
	colors->color5 = FUSCHIA;
	colors->color6 = MAGENTA;
	colors->color7 = BRIGHT_PINK;
	colors->color8 = DARK_PURPLE;
	colors->color9 = ROYAL_BLUE;
	colors->color10 = TURQUOISE;
	return (*colors);
}
