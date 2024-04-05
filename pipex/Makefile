# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 10:43:29 by margueriteb       #+#    #+#              #
#    Updated: 2024/04/05 08:57:37 by margueriteb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./src/pipex.c ./src/error_msg.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT = libft.a
LIBFTD = libft/

all : $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTD)
	$(CC) $(CFLAG) $(LIBFTD)$(LIBFT) $(OBJ) -o $(NAME)
	
clean:
	@$(MAKE) -C $(LIBFTD)
	@$(RM) $(OBJ) $(NAME)
	
fclean: clean
	@$(RM)
	$(MAKE) -C $(LIBFTD) fclean

re: fclean all