/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:41:49 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 18:08:23 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	ft_power_complex(t_complex a, int n)
{
	t_complex	tmp;

	tmp = a;
	if (n == 0)
	{
		tmp.i = 0;
		tmp.r = 0;
		return (tmp);
	}
	if (n == 1)
		return (tmp);
	tmp = ft_power_complex(a, n / 2);
	if (n % 2 == 0)
		return (ft_multiplication_complex(tmp, tmp));
	return (ft_multiplication_complex(a, ft_multiplication_complex(tmp, tmp)));
}
