/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:07:27 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/01 14:07:43 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_fractal
{
	t_color_palette		palette;
	int					iteration;
	t_complex			min;
	t_complex			max;
	double				zoom_value;
	unsigned int		current_coloring;
	t_complex			delta;
	t_complex			julia;
}	t_fractal;

#endif