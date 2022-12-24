/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:44:09 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/24 02:04:31 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	arguments_error(char flag)
{
	if (flag == 0)
		printf("Error:No arguments\n");
	else if (flag == 1)
		printf("Error:Too many arguments!\n");
	else if (flag == 2)
		printf("Error:Incorrect input\n");
	printf("You need to select a fractal\n");
	printf("0 = Mandelbrot\n");
	printf("1 = Julia\n");
	printf("Example:./fractol 0\n");
	printf("Exiting program\n");
	exit(1);
}
