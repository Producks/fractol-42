/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:21 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/28 07:14:14 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/hooks.h"
#include "../include/fractol.h"
#include "../include/complex.h"
#include "../include/input.h"
#include "../include/error.h"
#include "../include/calculus.h"
#include "../include/color_palette.h"
#include "../include/update_image.h"

/*Responsible for initializing values at the startup needed for later*/
static void	ft_init_fractal_config(t_fractal *config)
{
	config->iteration = 20.0;
	config->max.r = 2.0;
	config->min.r = -2.0;
	config->min.i = -2.0;
	config->max.i = config->min.i + (config->max.r - config->min.r) * HEIGHT
		/ WIDTH;
	config->zoom_value = 0.0;
	config->julia.r = 0.0;
	config->julia.i = 0.0;
	config->current_coloring = 0;
	config->palette = create_color_palette(config->iteration, 0);
}

/*Responsible for getting the function for the fractal
that will be getting displayed. Get stored in the struct for later*/
static void	get_function(int argc, char **argv, t_param *params)
{
	if (argc == 1)
		arguments_error(0);
	else if (argc > 2)
		arguments_error(1);
	else if (argv[1][0] == '0' && argv[1][1] == '\0')
		params->function = &mandelbrot_math;
	else if (argv[1][0] == '1' && argv[1][1] == '\0')
	{
		params->morbing = true;
		params->function = &julia_math;
	}
	else if (argv[1][0] == '2' && argv[1][1] == '\0')
		params->function = &burningship_math;
	else if (argv[1][0] == '3' && argv[1][1] == '\0')
		params->function = &tricorn_math;
	else if (argv[1][0] == '4' && argv[1][1] == '\0')
		params->function = &newton_math;
	else
		arguments_error(2);
}

int32_t	main(int argc, char **argv)
{
	t_param		param;

	get_function(argc, argv, &param);
	param.mlx = mlx_init(WIDTH, HEIGHT, "🦆Fractol 42🦆", true);
	ft_init_fractal_config(&param.config);
	param.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
	update_image(&param);
	mlx_image_to_window(param.mlx, param.img, 0, 0);
	mlx_loop_hook(param.mlx, &loop_hook, &param);
	mlx_scroll_hook(param.mlx, &scroll_hook, &param);
	mlx_cursor_hook(param.mlx, &mouse_position, &param);
	mlx_loop(param.mlx);
	mlx_terminate(param.mlx);
	free_color_palette(param.config.palette);
	puts("Bu Bye");
	return (EXIT_SUCCESS);
}
