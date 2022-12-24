/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:38:08 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/24 15:49:24 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FRACTOL_H
# define FRACTOL_H

# include "../libs/MLX42/MLX42.h"
# include "../include/complex.h"
# include "../include/color_palette.h"
# define WIDTH 550
# define HEIGHT 550

typedef struct s_fractal
{
	t_color_palette		palette;
	unsigned int		iteration;
	t_complex			min;
	t_complex			max;
	double				zoom_value;
	unsigned int		current_coloring;
	t_complex			delta;
	t_complex			julia;
}	t_fractal;

typedef struct s_param
{
	t_fractal		config;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*iteration_counter;
	int				flag;
	unsigned int	(*function)(t_complex constant, t_fractal *config,
			unsigned int x, unsigned int y);
}	t_param;

#endif