/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:32:15 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/03 03:21:15 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/input.h"
#include "../include/print_text.h"

/*Check for key presses*/
void	loop_hook2(void *params)
{
	t_param	*param;

	param = params;
	if (mlx_is_key_down(param->mlx, MLX_KEY_X))
		color_swap(params, 1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_Z))
		color_swap(params, 0);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_H))
		print_controls();
	else if (mlx_is_key_down(param->mlx, MLX_KEY_C) && param->morbing == true)
		morbing_julia(params);
}

/*Check for key presses*/
void	loop_hook(void *params)
{
	t_param	*param;

	param = params;
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->mlx);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_UP))
		move_camera(params, 0, -0.1, param->config.zoom_value);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_DOWN))
		move_camera(params, 0, 0.1, param->config.zoom_value);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_LEFT))
		move_camera(params, -0.1, 0, param->config.zoom_value);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_RIGHT))
		move_camera(params, 0.1, 0, param->config.zoom_value);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_W))
		iteration_modifier(params, -1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_Q))
		iteration_modifier(params, 1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_A))
		iteration_modifier(params, 10);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_S))
		iteration_modifier(params, -10);
}

/*Update mouse position in real time, this get called every frame*/
void	mouse_position(double xpos, double ypos, void *params)
{
	t_param	*param;

	param = params;
	param->config.delta.r = xpos;
	param->config.delta.i = ypos;
}

/*Check if scroll happened*/
void	scroll_hook(double xdelta, double ydelta, void *params)
{
	t_param	*param;

	param = params;
	if (ydelta > 0)
		zoom(param, 1.1, param->config.delta.r, param->config.delta.i);
	else if (ydelta < 0)
		zoom(param, 0.9, param->config.delta.r, param->config.delta.i);
}

void	loop(t_param *param)
{
	mlx_loop_hook(param->mlx, &loop_hook, param);
	mlx_loop_hook(param->mlx, &loop_hook2, param);
	mlx_scroll_hook(param->mlx, &scroll_hook, param);
	mlx_cursor_hook(param->mlx, &mouse_position, param);
	mlx_loop(param->mlx);
}
