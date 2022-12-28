/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:10:18 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/19 02:10:18 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CALCULUS_H
# define CALCULUS_H

unsigned int	julia_math(t_complex constant,
					t_fractal *config, unsigned int x, unsigned int y);
unsigned int	mandelbrot_math(t_complex constant,
					t_fractal *config, unsigned int x, unsigned int y);
unsigned int	burningship_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);
unsigned int	tricorn_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);
unsigned int	phoenix_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);
unsigned int	newton_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);

#endif
