# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 22:52:19 by ddemers           #+#    #+#              #
#    Updated: 2022/12/17 22:52:19 by ddemers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable #
NAME = fractol
# Compile stuff #
CC = gcc
CFGLAGS = -Wall -Werror -Wextra
LINUX = -ldl -lglfw -pthread -lm
# REMOVE #
REMOVE = rm -f
# LIBS #
MLX = libs/libmlx42.a
LIBFT = libs/libft.a
# OBJS #
OBJS = ${SRC:.c=.o}
# Source #
SRC = 	./src/calculus.c \
		./src/color_palette.c \
		./src/complex_math.c \
		./src/complex.c \
		./src/color_algo.c \
		./src/input.c \
		./src/hooks.c \
		./src/error.c \
		./src/update_image.c \
		./src/fractol.c
# Colors #
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

$(NAME): ${OBJS}
	${CC} $(CFGLAGS) $(OBJS) $(MLX) $(LIBFT) $(LINUX) -I /include -o ${NAME}
	@echo "$(GREEN)Nothing broke"
all:$(NAME)
clean:
	$(REMOVE) $(OBJS)
	@echo "⚠️$(RED)DELETING ALL FILES FROM THE COMPUTER$(WHITE)⚠️"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "$(PURPLE)SO BAD $(YELLOW)LOL"
re: fclean all
	@echo "$(PURPLE)BAD"

.PHONY: all clean fclean re