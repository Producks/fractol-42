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

void	move_camera(t_param *param, double distance, char direction)
{
	t_complex	center;

	center.r = param->config.max.r - param->config.min.r;
	center.i = param->config.max.i - param->config.min.i;
	if (direction == UP)
	{
		param->config.max.i += center.i * distance;
		param->config.min.i += center.i * distance;
	}
	else if (direction == DOWN)
	{
		param->config.max.i -= center.i * distance;
		param->config.min.i -= center.i * distance;
	}
	else if (direction == LEFT)
	{
		param->config.max.r += center.r * distance;
		param->config.min.r += center.r * distance;
	}
	else if (direction == RIGHT)
	{
		param->config.max.r -= center.r * distance;
		param->config.min.r -= center.r * distance;
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
	param->config.palette
		= create_color_palette(NULL, param->config.iteration);
	ft_update_image(param->img, &param->config);
}

void	zoom(t_param *param, double zoom_new_value, double x, double y)
{
	t_complex	mouse;

	mouse = real_to_complex(x, y, param->config.min, param->config.max);
	param->config.min.r = mouse.r - (mouse.r - param->config.min.r)
		/ zoom_new_value;
	param->config.max.r = mouse.r + (param->config.max.r - mouse.r)
		/ zoom_new_value;
	param->config.min.i = mouse.i - (mouse.i - param->config.min.i)
		/ zoom_new_value;
	param->config.max.i = mouse.i + (param->config.max.i - mouse.i)
		/ zoom_new_value;
	ft_update_image(param->img, &param->config);
}
