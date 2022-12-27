/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:58:51 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 15:58:51 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/complex.h"
#include "../include/fractol.h"

t_complex	real_to_complex(int x, int y, t_complex min, t_complex max)
{
	t_complex	res;

	res.r = min.r + ((x * (max.r - min.r)) / (double)WIDTH);
	res.i = min.i + ((y * (max.i - min.i)) / (double)HEIGHT);
	return (res);
}

t_complex	ft_complex_contructor(double x, double y)
{
	t_complex	complex;

	complex.r = x;
	complex.i = y;
	return (complex);
}

t_complex	ft_addition_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

t_complex	ft_subtraction_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;
	return (result);
}

t_complex	ft_multiplication_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = (a.r * b.r) - (a.i * b.i);
	result.i = (a.r * b.i) + (a.i * b.r);
	return (result);
}
