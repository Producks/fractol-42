/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.h                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:11:50 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/17 14:11:50 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_PALETTE_H
# define COLOR_PALETTE_H

//garbage ass norm forcing me to use an unsigned int here
typedef struct s_color_palette
{
	int				color_qty;
	uint32_t		*colors;
	unsigned int	(*color_palette_func)(int iteration,
			unsigned int max_iteration);
}	t_color_palette;

t_color_palette		create_color_palette(unsigned int iteration, int flag);
void				free_color_palette(t_color_palette palette);
uint32_t			get_rgba(int r, int g, int b, int a);

#endif
