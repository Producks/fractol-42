/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:09:15 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/28 03:13:59 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_MATH_H
# define COMPLEX_MATH_H

t_complex	addition_complex(t_complex a, t_complex b);
t_complex	subtraction_complex(t_complex a, t_complex b);
t_complex	multiplication_complex(t_complex a, t_complex b);
t_complex	absolute_complex(t_complex val);

#endif