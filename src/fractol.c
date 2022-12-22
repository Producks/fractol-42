/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:21 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/22 02:46:34 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../include/fractol.h"
#include "../include/complex.h"
#include "../include/calculus.h"
#include "../include/input.h"

static void	ft_init_fractal_config(t_fractal *config)
{
	config->iteration = 10.0;
	config->max.r = 2.0;
	config->min.r = -2.0;
	config->min.i = -2.0;
	config->max.i = config->min.i + (config->max.r - config->min.r) * HEIGHT
		/ WIDTH;
	config->palette = create_color_palette(NULL, config->iteration);
	config->zoom_value = 1.00;
}

static void	loop_hook(void *params)
{
	t_param	*param;

	param = params;
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->mlx);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_UP))
		move_camera(params, 0.1, 3);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_DOWN))
		move_camera(params, 0.1, 2);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_LEFT))
		move_camera(params, 0.1, 0);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_RIGHT))
		move_camera(params, 0.1, 1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_E))
		iteration_modifier(params, -1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_F))
		iteration_modifier(params, 1);
	else if (mlx_is_key_down(param->mlx, MLX_KEY_V))
		zoom(params, 0.9);
}

/*DEFINE coloring_function_qty = 3
coloring_functions *functions = 
[gray_scale, black_white, sintheta]

unsigned int current_coloring = 0;

current_coloring = (color + 1) % coloring_function_qty
functions[current_coloring]*/
int32_t	main(int argc, char **argv)
{
	t_param		param;

	param.mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	ft_init_fractal_config(&param.config);
	param.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
	ft_update_image(param.img, &param.config);
	mlx_image_to_window(param.mlx, param.img, 0, 0);
	mlx_loop_hook(param.mlx, &loop_hook, &param);
	mlx_loop(param.mlx);
	mlx_terminate(param.mlx);
	return (EXIT_SUCCESS);
}
