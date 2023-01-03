/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:41:49 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/03 03:21:01 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

/*Converts pixels coordinates to complex numbers*/
t_complex	real_to_complex(int x, int y, t_complex min, t_complex max)
{
	t_complex	res;

	res.r = min.r + ((x * (max.r - min.r)) / (double)WIDTH);
	res.i = min.i + ((y * (max.i - min.i)) / (double)HEIGHT);
	return (res);
}

/*Negating the real part fixes a bug for Julia*/
t_complex	real_to_complex_julia(int x, int y, t_complex min, t_complex max)
{
	t_complex	res;

	res.r = min.r + ((x * (max.r - min.r)) / (double)WIDTH);
	res.i = min.i + ((y * (max.i - min.i)) / (double)HEIGHT);
	res.r = -res.r;
	return (res);
}

/*Build t_complex function*/
t_complex	complex_contructor(double x, double y)
{
	t_complex	complex;

	complex.r = x;
	complex.i = y;
	return (complex);
}
