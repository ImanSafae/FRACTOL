/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:31 by itaouil           #+#    #+#             */
/*   Updated: 2022/01/25 17:10:14 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colors	init_colors(t_colors *colors, int argc, char **argv)
{
	if (argc < 3)
		*colors = default_palette(colors);
	else
	{
		if (!ft_strncmp(argv[2], "biscuit", ft_strlen("biscuit") + 1))
			*colors = biscuit_palette(colors);
		else if (!ft_strncmp(argv[2], "iridescent",
				ft_strlen("iridescent") + 1))
			*colors = iridescent_palette(colors);
		else if (!ft_strncmp(argv[2], "teal", ft_strlen("teal") + 1))
			*colors = teal_palette(colors);
		else if (!ft_strncmp(argv[2], "pastel", ft_strlen("pastel") + 1))
			*colors = pastel_palette(colors);
		else if (!ft_strncmp(argv[2], "lys", ft_strlen("lys") + 1))
			*colors = lys_palette(colors);
		else
		{
			ft_putstr_fd("Unknown argument. Theme set to \"Psychedelic\".\n", 2);
			*colors = default_palette(colors);
		}
	}
	return (*colors);
}

void	parse_args(char **argv, t_numbers *num)
{
	char	*fractal_type;

	fractal_type = uncapitalize(argv[1]);
	if (!ft_strncmp(fractal_type, "mandelbrot", ft_strlen("mandelbrot") + 1))
	{
		num->pattern = MANDELBROT;
		num->max_iteration = 50;
	}
	else if (!ft_strncmp(fractal_type, "julia", ft_strlen("julia") + 1))
	{
		num->pattern = JULIA;
		num->c_r = 0.285;
		num->c_i = 0.01;
		num->max_iteration = 30;
	}
}

char	*uncapitalize(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

void	manage_errors(int argc, char **argv, t_numbers *num)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Incorrect number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	parse_args(argv, num);
	if (num->pattern != JULIA && num->pattern != MANDELBROT)
	{
		ft_putstr_fd("Unrecognized argument.", 2);
		ft_putstr_fd("You can draw the following fractal patterns :\n", 2);
		ft_putstr_fd("- Mandelbrot\n", 2);
		ft_putstr_fd("- Julia\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	send_instructions(void)
{
	ft_putstr_fd("You can try out different color palettes", 1);
	ft_putstr_fd(" by adding an argument to your command line.\n", 1);
	ft_putstr_fd("The default theme is \"Psychedelic\".\n", 1);
	ft_putstr_fd("The available color palettes are the following ones:\n", 1);
	ft_putstr_fd("- \"biscuit\"\n", 1);
	ft_putstr_fd("- \"pastel\"\n", 1);
	ft_putstr_fd("- \"iridescent\"\n", 1);
	ft_putstr_fd("- \"teal\"\n", 1);
	ft_putstr_fd("- \"lys\"\n", 1);
	ft_putstr_fd("For example, try typing \"julia pastel\". Have fun!\n", 1);
}
