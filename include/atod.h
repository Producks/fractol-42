/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:12:34 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/01 20:38:03 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOD_H
# define ATOD_H

typedef struct s_atod
{
	int		i;
	double	x;
	double	numb;
	double	frac;
	double	div;
}	t_atod;

double	atod(const char *str);

#endif