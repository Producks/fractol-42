/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:21 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/19 17:36:49 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../include/fractol.h"
#include "../include/complex.h"
#include "../include/calculus.h"

static void	ft_init_fractal_config(t_fractal *config)
{
	config->iteration = 2.0;
	config->min = ft_complex_contructor(-2.0, -2.0);
	config->max = ft_complex_contructor(2.0, 2.0);
	config->palette = create_color_palette(NULL, config->iteration);
}

static void	loop_hook(void *params)
{
	t_param	*param;

	param = params;
	if (mlx_is_key_down(param->mlx, MLX_KEY_UP))
	{
		param->config.iteration += 1;
		free_color_palette(param->config.palette);
		param->config.palette = create_color_palette(NULL, param->config.iteration);
		ft_update_image(param->img, &param->config);
		printf("iterations: %d\n", param->config.iteration);
	}
}

// static void	key_hook(mlx_key_data_t key_data, void *params)
// {
// 	static int test = 0;
// 	t_param	*param;

// 	param = params;
// 	if (key_data.key == MLX_KEY_ESCAPE)
// 		mlx_close_window(param->mlx);
// 	else if (key_data.key == MLX_KEY_LEFT)
// 	{
// 		param->config.iteration += 1;
// 		//free_color_palette(param->config.palette);
// 		//param->config.palette = create_color_palette(NULL, param->config.iteration);
// 		ft_update_image(param->img, &param->config);
// 		printf("iterations: %d\n", param->config.iteration);
		
// 	}
// 	else if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
// 	{
// 		// printf("test: %d\n", test);
// 		ft_update_image(param->img, &param->config);
// 		// printf("test: %d\n", test++);
// 	}
// }

int32_t	main(int argc, char **argv)
{
	t_param		param;
	
	param.mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	//if (!fractol.mlx)
	//	exit(EXIT_FAILURE);
	ft_init_fractal_config(&param.config);
	param.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
	ft_update_image(param.img, &param.config);
	mlx_image_to_window(param.mlx, param.img, 0, 0);
	mlx_loop_hook(param.mlx, &loop_hook, &param);
	//mlx_key_hook(param.mlx, &key_hook, &param);
	mlx_loop(param.mlx);
	mlx_terminate(param.mlx);
	return (EXIT_SUCCESS);
}
