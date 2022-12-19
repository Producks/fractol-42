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
    //colors = ft_split(str, ';');
    // if (!colors)
    //     ft_error(); // later
    //palette.color_qty = count_split_elements(colors);
    palette.colors = (uint32_t *)malloc((iteration + 1) * sizeof(uint32_t));
    // if (!palette.colors)
    // {
    //     ft_free(); // later
    //     ft_error(); // later
    // }
    while(++index <= iteration)
    {
        //colors[0] = #009B83
        //009B83FF
        palette.colors[index] = ft_colors2(index, iteration);
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

uint32_t ft_colors2(int iteration, unsigned int max_iteration)
{
	int gray_level = 255 * iteration / (max_iteration);
	return get_rgba(gray_level, gray_level, gray_level, 0xFF);
}

//create_color_palette("#009B83;#CBDAA4;#DFE5B3;#F36859;#CCCCCC")