/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 08:18:20 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/20 08:18:20 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  INPUT_H
# define INPUT_H

void	move_camera(t_param *param, double xdelta, double ydelta,
			double zoom_level);
void	iteration_modifier(t_param *param, int i);
void	zoom(t_param *param, double zoom_new_value, double x, double y);
void	morbing_julia(t_param *param);
void	color_swap(t_param *param, int flag);

#endif