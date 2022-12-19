/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:01 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/19 02:09:04 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/fractol.h"
#include "../include/complex.h"
#include "../include/basic_math.h"

unsigned int	ft_mandelbrot_math(t_complex constant, unsigned int iteration)
{
	unsigned int	counter;
	t_complex		val;

	counter = 0;
	val = ft_complex_contructor(0.0, 0.0);
	while (counter < iteration)
	{
		val = ft_power_complex(val, 2);
		val = ft_addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}

void	ft_update_image(mlx_image_t	*img, t_fractal *config)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	iteration;
	t_complex		constant;

	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		while (++x < WIDTH)
		{
			constant = real_to_complex(x, y, config->min, config->max);
			iteration = ft_mandelbrot_math(constant, config->iteration);
			mlx_put_pixel(img, x, y, config->palette.colors[iteration]);
		}
		x = -1;
	}
}
