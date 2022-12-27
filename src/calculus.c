/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:01 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/27 07:53:01 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "../include/fractol.h"
#include "../include/complex.h"
#include "../include/basic_math.h"

// f(z) = z² + c
unsigned int	ft_mandelbrot_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = 0;
	val = ft_complex_contructor(0.0, 0.0);
	while (counter < config->iteration)
	{
		val = ft_multiplication_complex(val, val);
		val = ft_addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}

// f(z) = z² + c
unsigned int	ft_julia_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = 0;
	val = real_to_complex(x, y, config->min, config->max);
	constant = ft_complex_contructor(config->julia.r, config->julia.i);
	while (counter < config->iteration)
	{
		val = ft_multiplication_complex(val, val);
		val = ft_addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}

//f(z)=abs(z)^2+c
unsigned int	ft_burningship_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = 0;
	val = ft_complex_contructor(0.0, 0.0);
	while (counter < config->iteration)
	{
		val = ft_multiplication_complex(val, val);
		val = ft_addition_complex(val, constant);
		val = ft_absolute_complex(val);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}

//f(z)=conj(z)^2 + c
unsigned int	ft_tricorn_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = 0;
	val = ft_complex_contructor(0.0, 0.0);
	while (counter < config->iteration)
	{
		val.i = -val.i;
		val = ft_multiplication_complex(val, val);
		val = ft_addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}

//f(z)=z3-1
unsigned int	ft_newton_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;
	t_complex		temp;

	counter = 0;
	val = ft_complex_contructor(0.0, 0.0);
	while (counter < config->iteration)
	{
		val = ft_multiplication_complex(val, ft_multiplication_complex(val, val));
		val = ft_addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
		counter++;
	}
	return (counter);
}
void	ft_update_image(t_param *param)
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
			constant = real_to_complex(x, y,
					param->config.min, param->config.max);
			iteration = param->function(constant, &param->config, x, y);
			mlx_put_pixel(param->img, x, y,
				param->config.palette.colors[iteration]);
		}
		x = -1;
	}
}
