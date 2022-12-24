/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:33:11 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 14:33:11 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "../include/color_palette.h"
#include "../include/color_algo.h"

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// if (!palette.colors)
// {
//     ft_free(); // later
//     ft_error(); // later
// }
t_color_palette	create_color_palette(const char *str, const int iteration)
{
	t_color_palette	palette;
	char			**colors;
	unsigned int	index;

	index = -1;
	palette.colors = (uint32_t *)malloc((iteration + 1) * sizeof(uint32_t));
	while (++index <= iteration)
		palette.colors[index] = rainbow(index, iteration);
	return (palette);
}

void	free_color_palette(t_color_palette palette)
{
	free(palette.colors);
	palette.colors = NULL;
}
