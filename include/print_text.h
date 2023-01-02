/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:46:35 by ddemers           #+#    #+#             */
/*   Updated: 2023/01/02 08:15:37 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PRINT_TEXT_H
# define PRINT_TEXT_H

// Colors ~
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

void	arguments_error(char flag);
void	julia_arguments_errors(t_param *param);
void	malloc_palette_error(t_param *param);
void	print_controls(void);
void	failure(t_param *param, int flag);

#endif