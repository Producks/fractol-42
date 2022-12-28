/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_algo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:07:07 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/19 19:07:07 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_ALGO_H
# define COLOR_ALGO_H

uint32_t	grey_scale(int iteration, unsigned int max_iteration);
uint32_t	wave(int iteration, unsigned int max_iteration);
uint32_t	rainbow(int iteration, unsigned int max_iteration);
uint32_t	awesome(int iteration, unsigned int max_iteration);
uint32_t	monochrome(int iteration, unsigned int max_iteration);

#endif