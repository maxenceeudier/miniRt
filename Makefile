# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 15:52:00 by meudier           #+#    #+#              #
#    Updated: 2022/08/29 18:10:02 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror -g

NAME = miniRt

SRC = main.c split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c  \
	destroy.c loop_event.c check_extension.c init_data.c
	

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
