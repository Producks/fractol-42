/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:21 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/31 01:50:51 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/main.h"
#include "../include/hooks.h"
#include "../include/complex.h"
#include "../include/input.h"
#include "../include/print_text.h"
#include "../include/calculus.h"
#include "../include/color_palette.h"
#include "../include/update_image.h"

/*Responsible for initializing values at the startup needed for later*/
static void	init_fractal_config(t_fractal *config, t_param *param)
{
	config->iteration = 20.0;
	config->max.r = 2.0;
	config->min.r = -2.0;
	config->min.i = -2.0;
	config->max.i = config->min.i + (config->max.r - config->min.r) * HEIGHT
		/ WIDTH;
	config->zoom_value = 1.0;
	config->julia.r = 0.0;
	config->julia.i = 0.0;
	config->current_coloring = 0;
	config->palette = create_color_palette(config->iteration, 0, param);
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
	else
		arguments_error(2);
}

/*Responsible for printing the filter used for one of the color
palette, also check for errors.*/
static void	filter_init(t_param *param)
{
	xpm_t	*xpm;
	int32_t	error_check;

	xpm = mlx_load_xpm42("./img/wtf.xpm42");
	param->filter = mlx_texture_to_image(param->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	error_check = mlx_image_to_window(param->mlx, param->filter, 0, 0);
	if (error_check == -1)
		failure(param, 1);
}

/*Responsible for printing the fractal on screen,
also check for errors.*/
static void	fractal_init(t_param *param)
{
	int32_t	error_check;

	param->img = mlx_new_image(param->mlx, WIDTH, HEIGHT);
	if (!param->img)
	{
		mlx_delete_image(param->mlx, param->filter);
		failure(param, 1);
	}
	error_check = mlx_image_to_window(param->mlx, param->img, 0, 0);
	if (error_check == -1)
	{
		mlx_delete_image(param->mlx, param->filter);
		mlx_delete_image(param->mlx, param->img);
		failure(param, 1);
	}
	update_image(param);
}

int	main(int argc, char **argv)
{
	t_param		param;

	get_function(argc, argv, &param);
	param.mlx = mlx_init(WIDTH, HEIGHT, "Fractol 42 ddemers42🦆", false);
	if (!param.mlx)
		failure(&param, 0);
	init_fractal_config(&param.config, &param);
	filter_init(&param);
	fractal_init(&param);
	loop(&param);
	mlx_delete_image(param.mlx, param.filter);
	mlx_delete_image(param.mlx, param.img);
	mlx_terminate(param.mlx);
	free_color_palette(param.config.palette);
	printf("Buh Bye!\n");
	return (0);
}
