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
# LINUX and WSL WINDOWS FLAG #
LINUX = -ldl -lglfw -pthread -lm
# MAC FLAG #
MAC = libmlx42.a -I /include -lglfw -pthread -lm
# REMOVE #
REMOVE = rm -f
# LIBS #
MLX_PATH = ./libs/
LIB_EXISTS = $(shell [ -f path/to/lib/build/libmylib.a ] && echo 1 || echo 0)
CLONE = git clone https://github.com/codam-coding-college/MLX42.git
MLX = libs/libmlx42.a
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
		./src/print_text.c \
		./src/update_image.c \
		./src/main.c
# Colors #
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

$(NAME): lib ${OBJS}
	${CC} $(CFGLAGS) $(OBJS) $(MLX) $(LINUX) -I /include -o ${NAME}
	@echo "🎉$(GREEN)Everything compiled!$(WHITE)🎉"
	@echo "$(YELLOW)                  _      _      _"
	@echo "By: Ddmers@42  __(.)< __(.)> __(.)="
	@echo "Version 1.01   \___)  \___)  \___) $(WHITE)"

lib:
	@if [ ! -d "libs" ]; then \
		@echo "$(BLUE)Cloning MLX42..."
	fi
	@echo "test"
all: lib $(NAME)

clean:
	$(REMOVE) $(OBJS)
	@echo "⚠️$(RED)DELETING ALL FILES FROM THE COMPUTER$(WHITE)⚠️"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "$(PURPLE)SO BAD $(YELLOW)LOL"

re: fclean all
	@echo "$(PURPLE)Relink Successful! $(WHITE)"

.PHONY: all clean fclean re