/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:01 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 18:08:27 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/fractol.h"
#include "../include/complex.h"

unsigned int	ft_mandelbrot_math(t_complex constant, unsigned int iteration)
{
	unsigned int	counter;
	t_complex		val;

	counter = 0;
	val = ft_complex_contructor(0.0, 0.0);
	while (counter < iteration)
	{
		val = ft_multiplication_complex(val, val);
		val = ft_addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}

void	ft_update_image(mlx_image_t	*img, t_fractal *config)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	iteration;
	t_complex		constant;

	i = -1;
	j = -1;
	while (++i < HEIGHT)
	{
		while (++j < WIDTH)
		{
			constant = real_to_complex(j, i, config->min, config->max);
			iteration = ft_mandelbrot_math(constant, config->iteration);
			mlx_put_pixel(img, j, i, config->palette.colors[iteration]);
		}
		j = -1;
	}
}
