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
#include "../include/color_palette.h"
#include "../libs/Libft/libft.h"

static int count_split_elements(char **str)
{
    int index;

    if (!str)
        return (0);
    index = 0;
    while (str[index])
        index++;
    return (index);
}

t_color_palette  create_color_palette(const char *str, const int iteration)
{
    t_color_palette palette;
    char            **colors;
    unsigned int    index;

    index = -1;
    colors = ft_split(str, ';');
    // if (!colors)
    //     ft_error(); // later
    palette.color_qty = count_split_elements(colors);
    palette.colors = (uint32_t *)malloc(iteration * sizeof(uint32_t));
    // if (!palette.colors)
    // {
    //     ft_free(); // later
    //     ft_error(); // later
    // }
    while(++index < iteration)
    {
        //colors[0] = #009B83
        //009B83FF
        palette.colors[index] = ft_colors(index, 0);
    }
    //ft_free_split(colors);
    return(palette);
}

void free_color_palette(t_color_palette palette)
{
    free(palette.colors);
    palette.colors = NULL;
}

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_colors(int iteration, int palette)
{
	int			red;
	int			green;
	int			blue;
	uint32_t	result;

	if (palette == 0)
	{
		red = abs(iteration) * 25;
		green = abs(iteration) * 25;
		blue = abs(iteration) * 25;
		result = get_rgba(red, green, blue, 0xFF);
		return (result);
	}
	else if (palette == 1)
	{
		red = pow(iteration, 2);
		green = pow(iteration, 2);
		blue = pow(iteration, 2);
		result = get_rgba(red, green, blue, 0xFF);
		return (result);
	}
	else if (palette == 2)
	{
		red = iteration / 10;
		green = iteration % 10;
		blue = iteration * 10;
		result = get_rgba(red, green, blue, 0xFF);
		return (result);
	}
	result = get_rgba(0xFF, 0xFF, 0xFF, 0xFF);
	return (result);
}


//create_color_palette("#009B83;#CBDAA4;#DFE5B3;#F36859;#CCCCCC")