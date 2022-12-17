/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:38:08 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 18:08:04 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libs/MLX42/MLX42.h"
#include "../include/complex.h"
#include "../include/color_palette.h"

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_fractal
{
	t_color_palette		palette;
	unsigned int		iteration;
	t_complex			min;
	t_complex			max;
} t_fractal;

void			ft_update_image(mlx_image_t	*img, t_fractal *config);
unsigned int	ft_mandelbrot_math(t_complex constant, unsigned int iteration);

#endif