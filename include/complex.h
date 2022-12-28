/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:58:54 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 15:58:54 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double	i;
	double	r;
}	t_complex;

t_complex	real_to_complex(int x, int y, t_complex min, t_complex max);
t_complex	complex_contructor(double x, double y);

#endif
