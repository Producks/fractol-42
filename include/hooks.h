/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:35:14 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/29 09:16:06 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  HOOKS_H
# define HOOKS_H

void	loop_hook(void *params);
void	loop_hook2(void *params);
void	mouse_position(double xpos, double ypos, void *params);
void	scroll_hook(double xdelta, double ydelta, void *params);
#endif