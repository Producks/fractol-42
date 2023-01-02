/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:59:08 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/19 18:59:08 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "../include/color_palette.h"

uint32_t	red_delicious(int iteration, int max_iteration)
{
	double	fraction;
	int		red;
	int		green;
	int		blue;

	fraction = (double)iteration / (double)max_iteration;
	if (iteration == max_iteration)
		return (get_rgba(0x0, 0x0, 0x0, 0xFF));
	if (fraction < 0.5)
	{
		red = (255 * (2 * fraction));
		green = 0;
		blue = (255 * (1 - 2 * fraction));
	}
	else
	{
		green = (255 * (1 - 2 * fraction));
		red = (255 * (2 * fraction - 1));
		blue = 0;
	}
	return (get_rgba(red, green, blue, 255));
}

uint32_t	binary(int iteration, unsigned int max_iteration)
{
	int	gray_level;

	gray_level = 255 * (iteration % 2);
	return (get_rgba(gray_level, gray_level, gray_level, 0xFF));
}

uint32_t	awesome(int iteration, unsigned int max_iteration)
{
	double	fraction;

	fraction = (double)iteration / (double)max_iteration;
	if (fraction < 1.0 / 7.0)
		return (get_rgba(0xFF, 0x00, 0x00, 255));
	else if (fraction < 2.0 / 7.0)
		return (get_rgba(0xFF, 0xA5, 0x00, 255));
	else if (fraction < 3.0 / 7.0)
		return (get_rgba(0xFF, 0xFF, 0x00, 255));
	else if (fraction < 3.5 / 7.0)
		return (get_rgba(0x00, 0x80, 0x00, 255));
	else if (fraction < 4.0 / 7.0)
		return (get_rgba(0x00, 0x00, 0xFF, 255));
	else if (fraction < 5.0 / 7.0)
		return (get_rgba(0x4B, 0x00, 0x82, 255));
	else if (fraction < 5.0 / 7.0)
		return (get_rgba(0xEE, 0x82, 0xEE, 255));
	else if (fraction < 6.0 / 7.0)
		return (get_rgba(0xFF, 0x00, 0xFF, 255));
	else if (fraction < 6.5 / 7.0)
		return (get_rgba(0xA0, 0x20, 0xF0, 255));
	else
		return (get_rgba(0x00, 0x00, 0x00, 255));
}

uint32_t	filter(int iteration, unsigned int max_iteration)
{
	double	fraction;
	int		red;
	int		green;
	int		blue;
	int		alpha;

	fraction = (double)iteration / (double)max_iteration;
	if (iteration == max_iteration)
		return (get_rgba(0x00, 0x00, 0x00, 0x150));
	if (fraction < 0.5)
	{
		red = (255 * (2 * fraction));
		green = 0;
		blue = (255 * (1 - 2 * fraction));
		alpha = 0;
	}
	else
	{
		green = (255 * (2 * fraction - 1));
		red = 0;
		blue = 0;
		alpha = 255;
	}
	return (get_rgba(red, green, blue, alpha));
}

uint32_t	random_generated(int iteration, unsigned int max_iteration)
{
	double	fraction;

	fraction = (double)iteration / (double)max_iteration;
	if (fraction < 1.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else if (fraction < 2.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else if (fraction < 3.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else if (fraction < 4.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else if (fraction < 5.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else if (fraction < 6.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else if (fraction < 7.0 / 7.0)
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
	else
		return (get_rgba(rand() % 256, rand() % 256, rand() % 256, 0xFF));
}
