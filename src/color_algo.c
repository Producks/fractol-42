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
#include <math.h>
#include "../include/color_palette.h"

uint32_t	grey_scale(int iteration, unsigned int max_iteration)
{
	int		gray_level;

	gray_level = 255 * iteration / (max_iteration);
	return (get_rgba(gray_level, gray_level, gray_level, 0xFF));
}

uint32_t	wave(int iteration, unsigned int max_iteration)
{
	int		gray_level;

	gray_level = 255 * (iteration % 2);
	return (get_rgba(gray_level, gray_level, gray_level, 0xFF));
}

uint32_t	rainbow(int iteration, unsigned int max_iteration)
{
	int	red;
	int	green;
	int	blue;

	green = 255 * iteration / (max_iteration);
    blue  = (int)fmin(255, fmax(0, 255 * sin(iteration / 8.0 + 2.0)));
    red   = (int)fmin(255, fmax(0, 255 * sin(iteration / 8.0 + 4.0)));
	return (get_rgba(red, green, blue, 0xFF));
}
