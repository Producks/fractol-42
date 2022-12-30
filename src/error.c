/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:44:09 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/29 10:06:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/fractol.h"

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
	printf("2 = Burning Ship\n");
	printf("3 = Tricorn\n");
	printf("Example:./fractol 0\n");
	printf("Exiting program\n");
	exit(1);
}

void	malloc_palette_error(void)
{
	perror("Malloc failed");
	exit(1);
}

void	print_controls(void)
{
	#define ANSI_COLOR_RED     "\x1b[31m"
	#define ANSI_COLOR_RESET   "\x1b[0m"
	printf(ANSI_COLOR_RED"This text is RED!\n");
	printf(" ***************************************************************\n");
	printf(" *           Here a list of the controls available             *\n");
	printf(" *Press H on the keyboard to see this menu show up again       *\n");
	printf(" *Press ESC on the keyboard to close the program               *\n");
	printf(" *Press + on the numpad to add +1 to the number iteration      *\n");
	printf(" *Press - on the numpad to lower -1 to the number of iteration *\n");
	printf(" *Press I on the keyboard to add +10 to the number of iter...  *\n");
	printf(" *Press L on the keyboard to lower +10 to the number of it...  *\n");
	printf(" *Press the arrow keys on the keyboard to move around          *\n");
	printf(" *Scroll the mouse wheel to zoom in or out where the cursor is *\n");
	printf(" *Scroll the mouse wheel to zoom to a specific location        *\n");
	printf(" *Press C on the keyboard to change color paletlete            *\n");
	printf(" *Press R on the keyboard to change to a randomly generated pal*\n");
	printf(" *Hold M while moving the mouse around to morb (Julia only)    *\n");
	printf(" *Version 1.01 made by Ddemers@42                              *\n");
	printf(" ***************************************************************\n");
	printf(ANSI_COLOR_RED"This text is RED!"ANSI_COLOR_RESET "\n");
}
