# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 11:23:03 by marbaron          #+#    #+#              #
#    Updated: 2024/04/29 11:29:34 by marbaron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
RM = rm -f

LIBFT = libft.a
LIBFTD = libft/

MLX = libmlx.a
MLXPATH = mlx/

all : $(LIBFTD)$(LIBFT) $(NAME)

$(MLXPATH)$(MLX):
	@$(MAKE) -C $(MLXPATH)

$(LIBFTD)$(LIBFT): $(MLXPATH)$(MLX)
	$(MAKE) -C $(LIBFTD)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFTD)$(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)
clean:
	@$(RM) $(OBJ) $(NAME)
fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C $(LIBFTD) fclean
re: fclean all
