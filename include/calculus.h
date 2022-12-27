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

void			ft_update_image(t_param *param);
unsigned int	ft_julia_math(t_complex constant,
					t_fractal *config, unsigned int x, unsigned int y);
unsigned int	ft_mandelbrot_math(t_complex constant,
					t_fractal *config, unsigned int x, unsigned int y);
unsigned int	ft_burningship_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);
unsigned int	ft_tricorn_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);
unsigned int	ft_phoenix_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);
unsigned int	ft_newton_math(t_complex constant, t_fractal *config,
					unsigned int x, unsigned int y);

#endif
