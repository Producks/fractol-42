/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:38:08 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/02 15:44:54 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MAIN_H
# define MAIN_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "complex.h"
# include "color_palette.h"
# include "fractol.h"
# define WIDTH 750
# define HEIGHT 750	

typedef struct s_param
{
	t_fractal		config;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*filter;
	int				morbing;
	unsigned int	(*function)(t_complex constant, t_fractal *config,
			unsigned int x, unsigned int y);
	unsigned int	y;
}	t_param;

#endif