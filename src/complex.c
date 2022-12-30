/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:41:49 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/30 06:09:29 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/main.h"
#include "../include/complex.h"
#include "../include/complex_math.h"

t_complex	real_to_complex(int x, int y, t_complex min, t_complex max)
{
	t_complex	res;

	res.r = min.r + ((x * (max.r - min.r)) / (double)WIDTH);
	res.i = min.i + ((y * (max.i - min.i)) / (double)HEIGHT);
	return (res);
}

t_complex	complex_contructor(double x, double y)
{
	t_complex	complex;

	complex.r = x;
	complex.i = y;
	return (complex);
}
