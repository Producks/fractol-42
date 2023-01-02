/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:41:49 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/02 17:35:55 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

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
	t_complex	val;

	val.r = (max.r - min.r) / WIDTH * x + min.r;
	val.i = (max.i - min.i) / HEIGHT * y + min.i;
	val.r = -val.r;
	return (val);
}

t_complex	complex_contructor(double x, double y)
{
	t_complex	complex;

	complex.r = x;
	complex.i = y;
	return (complex);
}
