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

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/main.h"
#include "../include/color_palette.h"
#include "../include/color_algo.h"
#include "../include/update_image.h"
#include "../include/print_text.h"

/*Convert int into the correct color value,
taken from the MLX42 doc*/
uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	*get_color_palette_function(int flag)
{
	if (flag == 0)
		return (&red_delicious);
	else if (flag == 1)
		return (&awesome);
	else if (flag == 2)
		return (&binary);
	else if (flag == 3)
		return (&filter);
	else
		return (&random_generated);
}

/*Due to this project forcing you into garbage ways, this function got made.
This function pre compute every color palette in advance taking into 
account the max_iteration that is currently set and store all color values
in the heap to save performance*/
//#define malloc(...) NULL
//#define malloc(...) NULL
t_color_palette	create_color_palette(unsigned int iteration,
	int flag, t_param *param)
{
	t_color_palette	palette;
	char			**colors;
	unsigned int	index;

	index = -1;
	palette.colors = (uint32_t *)malloc((iteration + 1) * sizeof(uint32_t));
	if (!palette.colors)
		malloc_palette_error(param);
	palette.color_palette_func = get_color_palette_function(flag);
	while (++index <= iteration)
		palette.colors[index] = palette.color_palette_func(index, iteration);
	return (palette);
}

void	free_color_palette(t_color_palette palette)
{
	if (!palette.colors)
		return ;
	free(palette.colors);
	palette.colors = NULL;
}
