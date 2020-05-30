# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oouklich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/14 01:58:23 by oouklich          #+#    #+#              #
#    Updated: 2020/05/29 15:43:44 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = shifumi

INC_DIR = inc

MLX_DIR = minilibx_linux
MLX_FLAGS = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
SDL2_FLAGS = -I $(INC_DIR)/SDL2

all: $(NAME)

$(NAME):
	make -C $(MLX_DIR)
	gcc -o $(NAME) src/main.c -L . -lshifumi -I $(INC_DIR) -lpthread $(MLX_FLAGS) $(SDL2_FLAGS)

clean:
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
