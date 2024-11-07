# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joschka <joschka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 11:18:15 by joschka           #+#    #+#              #
#    Updated: 2024/11/07 09:11:44 by joschka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
MLX_URL	:= https://github.com/42Paris/minilibx-linux.git
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./minilibx-linux
LIBFT	:= ./libft
LKLIBFT	:= -L $(LIBFT) -lft
HEADERS	:= -I ./include 
LIBS	:= -L ./minilibx-linux -lmlx -lX11 -lXext $(LKLIBFT)

SRCS	:=	./src/main.c \


OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

# checkmlx:
# 	@if [ -d "$(LIBMLX)" ]; then \
# 		echo "--> MLX42 directory found <--"; \
# 	else \
# 		echo "!! No MLX42 directory found !! -->"; \
# 		git clone $(MLX_URL) minilibx; \
# 	fi

libmlx:
	@make -C $(LIBMLX)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	@$(CC) $(DB) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && printf "Compiling: $(NAME)\n"

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBMLX) clean
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft libmlx