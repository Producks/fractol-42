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
#include <stdlib.h>
#include "../include/main.h"
#include "../include/color_algo.h"

/*Convert int into the correct color value,
taken from the MLX42 doc*/
uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/*Read the function name*/
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
in the heap to save performance
#define malloc(...) NULL*/
int	create_color_palette(t_color_palette *palette,
	unsigned int iteration, int flag)
{
	char			**colors;
	unsigned int	index;

	index = -1;
	palette->colors = (uint32_t *)malloc((iteration + 1) * sizeof(uint32_t));
	if (!palette->colors)
		return (-1);
	palette->color_palette_func = get_color_palette_function(flag);
	while (++index <= iteration)
		palette->colors[index] = palette->color_palette_func(index, iteration);
	return (0);
}

/*Free the color palette buffer we created*/
void	free_color_palette(t_color_palette palette)
{
	if (!palette.colors)
		return ;
	free(palette.colors);
	palette.colors = NULL;
}
