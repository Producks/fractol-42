/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:18:16 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/03 03:23:46 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../include/main.h"

/*Magic happens here! Convert pixel to a complex plane, then runs the algo
until it either explode or hit max_iteration. Then update the pixel on the
screen. Since colors are pre computed before this function, we get to save
resources*/
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

/*Function responsible to update the image on screen, this use
multithreading. A more optimal way to do this would be to
create 1 thread per core to save run time.*/
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
