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

#include <math.h>
#include "../include/complex.h"

/*Responsible to add complex numbers together*/
t_complex	addition_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

/*Responsible to subtract complex numbers together*/
t_complex	subtraction_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;
	return (result);
}

/*Responsible to multiply complex numbers together*/
t_complex	multiplication_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = (a.r * b.r) - (a.i * b.i);
	result.i = (a.r * b.i) + (a.i * b.r);
	return (result);
}

/*Responsible to absolute complex numbers, used for burning ship only*/
t_complex	absolute_complex(t_complex val)
{
	val.r = fabsl(val.r);
	val.i = fabsl(val.i);
	return (val);
}
