# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 10:43:29 by margueriteb       #+#    #+#              #
#    Updated: 2024/03/23 17:57:33 by margueriteb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./src/pipex.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft.a
LIBFTD = libft/

all : $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTD) 
	$(CC) $(CFLAG) $(LIBFTD)$(LIBFT) -o 
	
clean:
	@$(MAKE) -C $(LIBFTD)
	@$(RM) $(OBJS)
	
fclean: clean
	@$(RM)
	$(MAKE) -C $(LIBFTD) fclean

re: fclean all