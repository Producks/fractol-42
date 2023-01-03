/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:02:49 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/03 03:28:11 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/atod.h"

static void	check_dot(const char *str, t_atod *atod)
{
	if (str[atod->i] == '.')
	{
		atod->i++;
		while (str[atod->i] >= '0' && str[atod->i] <= '9')
		{
			atod->frac = atod->frac * 10 + (str[atod->i] - 48);
			atod->div *= 10;
			atod->i++;
		}
	}
}

static void	check_numbers(const char *str, t_atod *atod)
{
	while (str[atod->i] >= '0' && str[atod->i] <= '9')
	{
		atod->numb = atod->numb * 10 + (str[atod->i] - 48);
		atod->i++;
	}
}

static void	check_plus_neg(const char *str, t_atod *atod)
{
	if (str[atod->i] == '+' || str[atod->i] == '-')
	{
		if (str[atod->i] == '-')
			atod->x *= -1;
		atod->i++;
	}
}

static void	check_spaces(const char *str, t_atod *atod)
{
	while (str[atod->i] == 32 || str[atod->i] == '\f' || str[atod->i] == '\n'
		|| str[atod->i] == '\r' || str[atod->i] == '\t' || str[atod->i] == '\v')
		atod->i++;
}

/*Responsible for the arguments of the Julia set, turn the arguments into
doubles. Pretty similar to atoi but for doubles*/
double	atod(const char *str)
{
	t_atod	atod;

	atod.i = 0;
	atod.x = 1;
	atod.numb = 0;
	atod.frac = 0;
	atod.div = 1;
	if (!str)
		return (0);
	check_spaces(str, &atod);
	check_plus_neg(str, &atod);
	check_numbers(str, &atod);
	check_dot(str, &atod);
	return ((atod.numb + atod.frac / atod.div) * atod.x);
}
