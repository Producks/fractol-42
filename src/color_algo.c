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


//  R   G   B
//  66  30  15 # brown 3
//  25   7  26 # dark violett
//   9   1  47 # darkest blue
//   4   4  73 # blue 5
//   0   7 100 # blue 4
//  12  44 138 # blue 3
//  24  82 177 # blue 2
//  57 125 209 # blue 1
// 134 181 229 # blue 0
// 211 236 248 # lightest blue
// 241 233 191 # lightest yellow
// 248 201  95 # light yellow
// 255 170   0 # dirty yellow
// 204 128   0 # brown 0
// 153  87   0 # brown 1
// 106  52   3 # brown 2
//21
uint32_t	grey_scale(int iteration, unsigned int max_iteration)
{
	float fraction;

	fraction = (float)iteration / (float)max_iteration;
	if (fraction < 0.5 / 7.0)
        return get_rgba(0, 255, 100, 255);
    else if (fraction < 1.0 / 7.0)
        return get_rgba(0, 7, 100, 255);
	else if (fraction < 1.5 / 7.0)
		return (get_rgba(255, 255, 255, 255));
    else if (fraction < 2.0 / 7.0) 
        return (get_rgba(12, 44, 138, 255));
    else if (fraction < 3.0 / 7.0)
        return (get_rgba(255, 255, 0, 255));
    else if (fraction < 4.0 / 7.0)
        return (get_rgba(0, 255, 0, 255));
    else if (fraction < 5.0 / 7.0)
        return (get_rgba(0, 0, 255, 255));
    else if (fraction < 6.0 / 7.0)
        return (get_rgba(75, 0, 130, 255));
	else 
        return (get_rgba(0, 0, 0, 255));
}

uint32_t	wave(int iteration, unsigned int max_iteration)
{
	int		gray_level;

	gray_level = 255 * (iteration % 2);
	return (get_rgba(gray_level, gray_level, gray_level, 0xFF));
}
// #000000
// #202020
// #404040
// #606060
// #204040
// #204020
// #606040

// #404020
// #002020
// #60f0c0
uint32_t awesome(int iteration, unsigned int max_iteration)
{
	float fraction;

	fraction = (float)iteration / (float)max_iteration;
    if (fraction < 1.0/7.0)
        return get_rgba(0x00, 0x00, 0x00, 255);
    else if (fraction < 2.0/7.0) 
        return (get_rgba(0x20, 0x20, 0x20, 255));
    else if (fraction < 3.0/7.0)
        return (get_rgba(0x40, 0x40, 0x40, 255));
	else if (fraction < 3.5 / 7.0)
		return (get_rgba(0x60, 0x60, 0x60, 255));
    else if (fraction < 4.0/7.0)
        return (get_rgba(0x20, 0x40, 0x40, 255));
    else if (fraction < 5.0/7.0)
        return (get_rgba(0x20, 0x40, 0x20, 255));
	else if (fraction < 5.0/7.0)
        return (get_rgba(0x60, 0x60, 0x40, 255));
    else if (fraction < 6.0/7.0)
        return (get_rgba(0x40, 0x40, 0x20, 255));
	else if (fraction < 6.5/7.0)
        return (get_rgba(0x00, 0x20, 0x20, 255));
	else 
        return (get_rgba(0x60, 0xF0, 0xC0, 255));
}
uint32_t monochrome(int iteration, unsigned int max_iteration)
{
   	float fraction;
    int intensity;

	fraction =  (float)iteration / (float)max_iteration;
	intensity = (int)(fraction * 255);
    return get_rgba(intensity, intensity, intensity, 255);
}

uint32_t rainbow(int iteration, unsigned int max_iteration)
{
    float fraction = (float)iteration / (float)max_iteration;
    int red = (int)(fraction * 255);
    int green = (int)(fraction * 255);
    int blue = (int)(fraction * 255);
    int alpha = (int)((1.0 - fraction) * 255);
    return get_rgba(red, green, blue, alpha);
}

