/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:21 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 18:08:10 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../include/fractol.h"
#include "../include/complex.h"

void	ft_init_fractal_config(t_fractal *config)
{
	config->iteration = 500.0;
	config->min = ft_complex_contructor(-2.0, -2.0);
	config->max = ft_complex_contructor(2.0, 2.0);
	config->palette = create_color_palette(NULL, config->iteration);
}

// void	hook(t_pic *fractol)
// {
// 	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(fractol->mlx);
// 	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
// 	{
// 		fractol->palette += 1;
// 		if (fractol->palette == 3)
// 			fractol->palette = 0;
// 		ft_update_image(fractol);
// 	}
// 	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
// 	{
// 		fractol->palette -= 1;
// 		if (fractol->palette == -1)
// 			fractol->palette = 2;
// 		ft_update_image(fractol);
// 	}
// 	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
// 	{
// 		fractol->iteration += 1;
// 		ft_update_image(fractol);
// 	}
// 	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
// 	{
// 		fractol->iteration -= 1;
// 		if (fractol->iteration == 0)
// 			fractol->iteration = 0;
// 		ft_update_image(fractol);
// 	}
// }

int32_t	main(int argc, char **argv)
{
	t_fractal	config;
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "42", true);
	//if (!fractol.mlx)
	//	exit(EXIT_FAILURE);
	ft_init_fractal_config(&config);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_update_image(img, &config);
	mlx_image_to_window(mlx, img, 0, 0);
	//mlx_loop_hook(fractol.mlx, (void *)&hook, &fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
