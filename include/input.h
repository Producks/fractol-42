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

# define LEFT 0
# define RIGHT 1
# define UP 3
# define DOWN 2

void	move_camera(t_param *param, double distance, int direction);
void	iteration_modifier(t_param *param, int i);
void	zoom(t_param *param, double zoom_new_value);

#endif