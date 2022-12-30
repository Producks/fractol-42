/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:18:16 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/29 23:47:27 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../include/fractol.h"
#include "../include/complex.h"

void	*thread_function(void *arg)
{
	t_param			*param;
	unsigned int	x;
	t_complex		constant;
	unsigned int	iteration;

	param = (t_param *)arg;
	x = -1;
	while (++x < WIDTH)
	{
		constant = real_to_complex(x, param->y, param->config.min,
				param->config.max);
		iteration = param->function(constant, &param->config, x,
				param->y);
		mlx_put_pixel(param->img, x, param->y,
			param->config.palette.colors[iteration]);
	}
	return (NULL);
}

//1 thread par core
// 100 4 25 thread
void	update_image(t_param *param)
{
	unsigned int	y;
	unsigned int	i;
	pthread_t		threads[HEIGHT];
	t_param			thread_params[HEIGHT];

	y = -1;
	i = -1;
	while (++y < HEIGHT)
	{
		thread_params[y] = *param;
		thread_params[y].y = y;
		pthread_create(&threads[y], NULL, thread_function, &thread_params[y]);
	}
	while (++i < HEIGHT)
		pthread_join(threads[i], NULL);
}
