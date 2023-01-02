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
CLONE = git clone https://github.com/codam-coding-college/MLX42.git;
MLX = MLX42/libmlx42.a
# RUN #
RUN = ./fractol 0
# OBJS #
OBJS = ${SRC:.c=.o}
# OS CHECK #
OS = $(shell uname)
# Source #
SRC = 	./src/calculus.c \
		./src/color_palette.c \
		./src/complex_math.c \
		./src/complex.c \
		./src/color_algo.c \
		./src/input.c \
		./src/hooks.c \
		./src/print_text.c \
		./src/atod.c \
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

#CHECK WHICH OS IS RUNNING TO GET THE CORRECT COMPILATION FLAG #
ifeq ($(OS), Linux)
	FLAGS = -ldl -lglfw -pthread -lm
else ifeq ($(OS), Darwin)
	FLAGS = libmlx42.a -I /include -lglfw -pthread -lm
endif

$(NAME): lib ${OBJS}
	${CC} $(CFGLAGS) $(OBJS) $(MLX) $(FLAGS) -I /include -o ${NAME}
	@echo "🎉$(GREEN)Everything compiled!$(WHITE)🎉"
	@echo "$(YELLOW)                  _      _      _"
	@echo "By: Ddmers@42  __(.)< __(.)> __(.)="
	@echo "Version 1.01   \___)  \___)  \___) $(WHITE)"

lib:
	@if [ ! -d "MLX42" ]; then \
		$(CLONE) \
	fi
	@make -C MLX42

all: $(NAME)

clean:
	@echo "⚠️$(RED)Cleaning .o⚠️$(WHITE)"
	@sleep 1 > /dev/null
	$(REMOVE) $(OBJS)
	@if [ -d "MLX42" ]; then \
		make clean -C MLX42; \
	fi
	@echo "🎉$(GREEN)Cleaning done!$(WHITE)🎉"

fclean: clean
	@echo "$(RED)Removing files..."
	@sleep 1 > /dev/null
	$(REMOVE) $(NAME)
	@echo "$(RED)Removing MLX Directory..."
	@sleep 1 > /dev/null
	@if [ -d "MLX42" ]; then \
		rm -rf MLX42; \
	fi
	@echo "🎉$(GREEN)Cleaning done!$(WHITE)🎉"

re: fclean all
	@echo "$(PURPLE)Relink Successful! $(WHITE)"
run: $(NAME) 
	$(RUN)
.PHONY: all clean fclean re run lib