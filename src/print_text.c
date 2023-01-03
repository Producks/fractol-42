/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:44:09 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/03 04:12:20 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/main.h"
#include "../include/print_text.h"

/*Used when the program and ran and no arguments or an invalid argument
was given. See explanation bellow for printf() converted to puts()*/
void	arguments_error(char flag)
{
	if (flag == 0)
		printf(RED "Error:No arguments\n" WHITE);
	else if (flag == 1)
		printf(RED "Error:Too many arguments!\n" WHITE);
	else if (flag == 2)
		printf(RED "Error:Incorrect input\n" WHITE);
	printf(
		"You need to select a fractal\n"
		"0 = Mandelbrot\n"
		"1 = Julia\n"
		"2 = Burning Ship\n"
		"3 = Tricorn\n"
		"Example:./fractol 0\n"
		"Exiting program\n");
	exit(1);
}

/*Print the text if the input for julia is incorrect*/
void	julia_arguments_errors(t_param *param)
{
	printf(
		RED "Error:Not enough arguments\n" WHITE
		"You need to provide 2 extra arguments for the Julia set\n"
		"3rd argument Real part\n"
		"4th argument Imaginary part\n"
		"Example:./fractal 1 0.3 0.6\n"
		"If the inputs are incorrect, the values will be adjusted to 0.0\n"
		"Exiting program\n");
	exit (1);
}

/*Text and error handling incase malloc fail for collor palette*/
void	malloc_palette_error(t_param *param)
{
	printf(RED "Error:Malloc Failed\n" WHITE);
	mlx_close_window(param->mlx);
	mlx_terminate(param->mlx);
	exit(1);
}

/*Get converted to puts() by the compiler, not sure we are allowed to use
that function. If we aren't, this bypass the restriction and we gain
performance over using printf*/
void	print_controls(void)
{
	printf(
		CYAN "\n"
		" ***************************************************************\n"
		" *           Here a list of the controls available             *\n"
		" *Press H on the keyboard to see this menu show up again       *\n"
		" *Press ESC on the keyboard to close the program               *\n"
		" *Press Q on the numpad to add +1 to the number iteration      *\n"
		" *Press W on the numpad to lower -1 to the number of iteration *\n"
		" *Press A on the keyboard to add +10 to the number of iter...  *\n"
		" *Press S on the keyboard to lower +10 to the number of it...  *\n"
		" *Press the arrow keys on the keyboard to move around          *\n"
		" *Scroll the mouse wheel to zoom in or out where the cursor is *\n"
		" *Scroll the mouse wheel to zoom to a specific location        *\n"
		" *Press Z on the keyboard to change color paletlete            *\n"
		" *Press X on the keyboard to change to a randomly generated pal*\n"
		" *Hold C while moving the mouse around to morb (Julia only)    *\n"
		" *Version 1.01 made by Ddemers@42                              *\n"
		" ***************************************************************\n"
		WHITE "\n");
}

/*Incase the MLX fail*/
void	failure(t_param *param, int flag)
{
	if (flag == 1)
	{
		free_color_palette(param->config.palette);
		mlx_close_window(param->mlx);
		mlx_terminate(param->mlx);
	}
	printf(RED "Error:MLX FAILURE\n" WHITE);
	exit(1);
}
