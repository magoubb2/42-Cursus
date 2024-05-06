# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 11:23:03 by marbaron          #+#    #+#              #
#    Updated: 2024/05/06 12:21:52 by margueriteb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c src/map.c src/map2.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -g
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
	@$(MAKE) -C $(LIBFTD)
	@$(RM) $(OBJ) $(NAME)
fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C $(LIBFTD) fclean
	@make -s clean -C $(MLXPATH)
re: fclean all
