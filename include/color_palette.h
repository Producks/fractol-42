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

typedef struct s_color_palette
{
	int			color_qty;
	uint32_t	*colors;
}	t_color_palette;

t_color_palette		create_color_palette(const char *str, const int iteration);
void				free_color_palette(t_color_palette palette);
uint32_t			ft_colors(int iteration, int palette);
uint32_t			ft_colors2(int iteration, unsigned int max_iteration);
uint32_t			get_rgba(int r, int g, int b, int a);

#endif
