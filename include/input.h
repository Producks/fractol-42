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

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

void	move_camera(t_param *param, double distance, char direction);
void	iteration_modifier(t_param *param, int i);
void	zoom(t_param *param, double zoom_new_value, double x, double y);

#endif