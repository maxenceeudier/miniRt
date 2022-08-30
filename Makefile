# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 15:52:00 by meudier           #+#    #+#              #
#    Updated: 2022/08/30 18:03:12 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror -g

NAME = miniRt

SRC = src/main.c \
	src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c  \
	src/tools/split.c src/tools/tools.c \
	src/window/destroy.c src/window/loop_event.c \
	src/parser/check.c src/parser/init_data.c src/parser/free_data.c \
	src/parser/parser.c src/parser/parser_obj.c \
	src/calcul/calcul1.c src/calcul/calcul2.c src/calcul/calcul3.c
	

OBJ = $(SRC:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd mlx_linux && make && cd ..
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus : $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) bonus

re: clean fclean all


.PHONY: re clean fclean 
