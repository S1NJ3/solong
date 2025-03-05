# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 16:55:23 by jrighi            #+#    #+#              #
#    Updated: 2025/03/05 18:19:47 by jrighi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I bibi -I utils -I libft -I gnl -I minilibx-linux
LIB = libft/libft.a
MLX = minilibx-linux/libmlx.a

SRCS =  so_long.c \
        verif/floodfill.c \
        verif/check1.c \
        verif/check2.c \
        utils/utils.c \
        utils/maptotab.c \
        gnl/get_next_line.c \
        gnl/get_next_line_utils.c \
        utils/init.c \
        utils/mlxutils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME) $(INC) -L libft -L minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
