/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 08:08:17 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/20 08:08:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../libs/Libft/libft.h"
#include "../include/fractol.h"
#include "../include/calculus.h"
#include "../include/input.h"

void	move_camera(t_param *param, double distance, int direction)
{
	t_complex	center;

	center.r = param->config.max.r - param->config.min.r;
	center.i = param->config.max.i - param->config.min.i;
	if (direction == LEFT)
	{
		param->config.max.r += center.r * distance;
		param->config.min.r += center.r * distance;
	}
	else if (direction == RIGHT)
	{
		param->config.max.r -= center.r * distance;
		param->config.min.r -= center.r * distance;
	}
	else if (direction == DOWN)
	{
		param->config.max.i -= center.r * distance;
		param->config.min.i -= center.r * distance;
	}
	else if (direction == UP)
	{
		param->config.max.i += center.r * distance;
		param->config.min.i += center.r * distance;
	}
	ft_update_image(param->img, &param->config);
}

void	iteration_modifier(t_param *param, int i)
{
	param->config.iteration += 50;
	if (param->config.iteration <= 1)
		param->config.iteration = 1;
	printf("%d\n", param->config.iteration);
	free_color_palette(param->config.palette);
	param->config.palette = create_color_palette(NULL, param->config.iteration);
	ft_update_image(param->img, &param->config);
}

void	zoom(t_param *param, double zoom_new_value)
{
	double	xcenter;
	double	ycenter;
	double	zoom;

	zoom = 0.2;
	xcenter = (param->config.min.r + param->config.max.r) / 2;
	ycenter = (param->config.min.i + param->config.max.i) / 2;
	param->config.min.r = xcenter - (xcenter - param->config.min.r) / zoom;
	param->config.max.r = xcenter + (param->config.max.r - xcenter) / zoom;
	param->config.min.i = ycenter - (ycenter - param->config.min.i) / zoom;
	param->config.max.i = ycenter + (param->config.max.i - ycenter) / zoom;
	ft_update_image(param->img, &param->config);
}
