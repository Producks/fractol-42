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

#include <stdio.h>
#include "../include/main.h"
#include "../include/update_image.h"
#include "../include/print_text.h"

void	move_camera(t_param *param, double xdelta, double ydelta,
	double zoom_level)
{
	xdelta /= zoom_level;
	ydelta /= zoom_level;
	param->config.max.i += ydelta;
	param->config.min.i += ydelta;
	param->config.max.r += xdelta;
	param->config.min.r += xdelta;
	update_image(param);
}

/*Responsible for changing the amount of iterations.*/
void	iteration_modifier(t_param *param, int i)
{
	param->config.iteration += i;
	if (param->config.iteration < 1)
		param->config.iteration = 1;
	printf("Iteration counter:%d\n", param->config.iteration);
	free_color_palette(param->config.palette);
	if (create_color_palette(&param->config.palette, param->config.iteration,
			param->config.current_coloring) == -1)
	{
		mlx_delete_image(param->mlx, param->filter);
		mlx_delete_image(param->mlx, param->img);
		malloc_palette_error(param);
	}
	update_image(param);
}

/*Responsible for the zoom where the cursor is located at*/
void	zoom(t_param *param, double zoom_new_value, double x, double y)
{
	t_complex	mouse;

	param->config.zoom_value += zoom_new_value;
	mouse = real_to_complex(x, y, param->config.min, param->config.max);
	param->config.min.r = mouse.r - (mouse.r - param->config.min.r)
		/ zoom_new_value;
	param->config.max.r = mouse.r + (param->config.max.r - mouse.r)
		/ zoom_new_value;
	param->config.min.i = mouse.i - (mouse.i - param->config.min.i)
		/ zoom_new_value;
	param->config.max.i = mouse.i + (param->config.max.i - mouse.i)
		/ zoom_new_value;
	update_image(param);
}

/*It's morbing time, responsible for changing the parameters in real time
of the Julia fractal. Key need to be held down to call this function
and it will change the fractal depending on the mouse position*/
void	morbing_julia(t_param *param)
{
	param->morbing = false;
	param->config.julia = real_to_complex(param->config.delta.r,
			param->config.delta.i, param->config.min, param->config.max);
	update_image(param);
	param->morbing = true;
}

/*Responsible for changing the color palette*/
void	color_swap(t_param *param, int flag)
{
	if (flag == 0)
		param->config.current_coloring = (param->config.current_coloring + 1)
			% 4;
	else
		param->config.current_coloring = 69;
	free_color_palette(param->config.palette);
	if (create_color_palette(&param->config.palette, param->config.iteration,
			param->config.current_coloring) == -1)
	{
		mlx_delete_image(param->mlx, param->filter);
		mlx_delete_image(param->mlx, param->img);
		malloc_palette_error(param);
	}
	update_image(param);
}
