/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:44:09 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/30 06:11:12 by ddemers          ###   ########.fr       */
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
		"0 = Mandelbrot\n;"
		"1 = Julia\n"
		"2 = Burning Ship\n"
		"3 = Tricorn\n"
		"Example:./fractol 0\n"
		"Exiting program\n");
	exit(1);
}

void	malloc_palette_error(t_param *param)
{
	perror("Malloc failed");
	mlx_close_window(param->mlx);
	mlx_terminate(param->mlx);
	exit(1);
}

/*Get converted to puts() by the compiler, not sure we are allowed to use
that function. If we aren't, this bypass the restriction and we gain
performance over using printf*/
void	print_controls(void)
{
	printf(RED "\n");
	printf(
		" ***************************************************************\n"
		" *           Here a list of the controls available             *\n"
		" *Press H on the keyboard to see this menu show up again       *\n"
		" *Press ESC on the keyboard to close the program               *\n"
		" *Press + on the numpad to add +1 to the number iteration      *\n"
		" *Press - on the numpad to lower -1 to the number of iteration *\n"
		" *Press I on the keyboard to add +10 to the number of iter...  *\n"
		" *Press L on the keyboard to lower +10 to the number of it...  *\n"
		" *Press the arrow keys on the keyboard to move around          *\n"
		" *Scroll the mouse wheel to zoom in or out where the cursor is *\n"
		" *Scroll the mouse wheel to zoom to a specific location        *\n"
		" *Press C on the keyboard to change color paletlete            *\n"
		" *Press R on the keyboard to change to a randomly generated pal*\n"
		" *Hold M while moving the mouse around to morb (Julia only)    *\n"
		" *Version 1.01 made by Ddemers@42                              *\n"
		" ***************************************************************\n");
	printf(WHITE "\n");
}

void	failure(t_param *param, int flag)
{
	if (flag == 1)
		mlx_terminate(param->mlx);
	perror("MLX:");
	exit(1);
}