/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:09:56 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:09:57 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colors	teal_palette(t_colors *colors)
{
	colors->divider = 6;
	colors->color1 = TEAL;
	colors->color2 = JUNGLE;
	colors->color3 = VERDIGRIS;
	colors->color4 = AQUAMARINE;
	colors->color5 = EGG_BLUE;
	colors->color6 = PALE_BLUE;
	return (*colors);
}

t_colors	pastel_palette(t_colors *colors)
{
	colors->divider = 6;
	colors->color1 = CLASSIC_ROSE;
	colors->color2 = MIMI_PINK;
	colors->color3 = LAVENDER_BLUSH;
	colors->color4 = MAGNOLIA;
	colors->color5 = PALE_LAVENDER;
	colors->color6 = MILD_LAVENDER;
	return (*colors);
}

t_colors	iridescent_palette(t_colors *colors)
{
	colors->divider = 6;
	colors->color1 = LAVENDER;
	colors->color2 = BABY_BLUE;
	colors->color3 = PISTACHIO;
	colors->color4 = MAGNOLIA;
	colors->color5 = PINK;
	colors->color6 = CREAM;
	return (*colors);
}

t_colors	biscuit_palette(t_colors *colors)
{
	colors->divider = 6;
	colors->color1 = MAX_PURPLE;
	colors->color2 = CRAYOLA;
	colors->color3 = QUARTZ;
	colors->color4 = VIOLET;
	colors->color5 = SALMON;
	colors->color6 = SAND;
	return (*colors);
}

t_colors	lys_palette(t_colors *colors)
{
	colors->divider = 6;
	colors->color1 = APRICOT;
	colors->color2 = PEACH;
	colors->color3 = LIGHTPINK;
	colors->color4 = PEARL;
	colors->color5 = TROPICAL;
	colors->color6 = PERI;
	return (*colors);
}
