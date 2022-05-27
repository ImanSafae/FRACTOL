/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:36 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:38 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_imagedata *image, int x, int y, int color)
{
	int		offset;
	char	*dst;

	offset = (y * image->line_length) + (x * (image->bits_per_pixel / 8));
	dst = image->addr + offset;
	*(unsigned int *)dst = color;
}

double	module(double x, double y)
{
	double	result;

	result = (x * x) + (y * y);
	return (result);
}
