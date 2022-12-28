/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:01 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/28 03:24:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "../include/fractol.h"
#include "../include/complex.h"
#include "../include/complex_math.h"

/*Formula: f(z) = z² + c
This run the formula until the number blows up or we reach max_iteration*/
unsigned int	mandelbrot_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = -1;
	val = complex_contructor(0.0, 0.0);
	while (++counter < config->iteration)
	{
		val = multiplication_complex(val, val);
		val = addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
	}
	return (counter);
}

/*Formula: f(z) = z² + c
This run the formula until the number blows up or we reach max_iteration*/
unsigned int	julia_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = -1;
	val = real_to_complex(x, y, config->min, config->max);
	constant = complex_contructor(config->julia.r, config->julia.i);
	while (++counter < config->iteration)
	{
		val = multiplication_complex(val, val);
		val = addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
	}
	return (counter);
}

/*Formula: f(z)=abs(z)^2+c
This run the formula until the number blows up or we reach max_iteration*/
unsigned int	burningship_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = -1;
	val = complex_contructor(0.0, 0.0);
	while (++counter < config->iteration)
	{
		val = multiplication_complex(val, val);
		val = addition_complex(val, constant);
		val = absolute_complex(val);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
	}
	return (counter);
}

/*Formula: f(z)=conj(z)^2 + c
This run the formula until the number blows up or we reach max_iteration*/
unsigned int	tricorn_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;
	t_complex		val;

	counter = -1;
	val = complex_contructor(0.0, 0.0);
	while (++counter < config->iteration)
	{
		val.i = -val.i;
		val = multiplication_complex(val, val);
		val = addition_complex(val, constant);
		if (pow(val.i, 2) + pow(val.r, 2) > 4.0)
			break ;
	}
	return (counter);
}

//f(z)=z3-1
unsigned int	newton_math(t_complex constant, t_fractal *config,
	unsigned int x, unsigned int y)
{
	unsigned int	counter;

	counter = 0;
	return (counter);
}
