# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joschka <joschka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 11:18:15 by joschka           #+#    #+#              #
#    Updated: 2024/11/08 11:36:42 by joschka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
CC		:= cc
MLX_URL	:= https://github.com/42Paris/minilibx-linux.git
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./minilibx-linux
LIBFT	:= ./libft
LKLIBFT	:= -L $(LIBFT) -lft
LKMLX	:= -L $(LIBMLX) -lmlx -lX11 -lXext
LIBS	:=  $(LKMLX) $(LKLIBFT)

SRCS	:=	./src/main.c \


OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	make -C $(LIBMLX)

libft:
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(LIBMLX) clean
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft libmlx