# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurso <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 17:09:16 by aurso             #+#    #+#              #
#    Updated: 2023/03/15 17:19:02 by aurso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBX = minilibx/libmlx_Linux.a -lX11 -lXext -lm

LIB = libft/libft.a

SRC = src/command.c src/floodfill.c src/close.c src/init_img.c src/main.c src/check_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "compiling..."
	make all -C libft/
	make -C minilibx/
	$(CC) $(CFLAGS) $(OBJ) $(LIBX) -o $(NAME) $(LIB)
	@echo "compiled💪"

clean:
	@echo "cleaning..."
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	@echo "cleaning all..."
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re

.SILENT:
