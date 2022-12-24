/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:32:15 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/24 03:54:10 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/input.h"

void	loop_hook(void *params)
{
	t_param	*param;

	param = params;
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->mlx);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_UP))
		move_camera(params, 0.1, 0b0);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_DOWN))
		move_camera(params, 0.1, 0b1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_LEFT))
		move_camera(params, 0.1, 0b10);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_RIGHT))
		move_camera(params, 0.1, 0b11);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_E))
		iteration_modifier(params, -1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_F))
		iteration_modifier(params, 1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_V))
		morbing_julia(params);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_Z))
		color_swap(params);
}

void	mouse_position(double xpos, double ypos, void *params)
{
	t_param	*param;

	param = params;
	param->config.delta.r = xpos;
	param->config.delta.i = ypos;
}

void	scroll_hook(double xdelta, double ydelta, void *params)
{
	t_param	*param;

	param = params;
	if (ydelta > 0)
		zoom(param, 1.1, param->config.delta.r, param->config.delta.i);
	else if (ydelta < 0)
		zoom(param, 0.9, param->config.delta.r, param->config.delta.i);
}
