# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 13:25:59 by margueriteb       #+#    #+#              #
#    Updated: 2024/03/04 15:03:19 by marbaron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}
 
NAME = libftprintf.a
 
CC	 = gcc
 
CFLAGS = -Wall -Wextra -Werror
 
all	: ${NAME}
 
${NAME}: ${OBJS}
					@ar -rcs  ${NAME} ${OBJS}
 
clean  :  
					@rm -f ${OBJS}
 
fclean : clean
					@rm -f ${NAME}
 
re     : fclean all
