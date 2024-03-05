/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/05 10:39:38 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* %c ft_putchar_fd_pf */

size_t	ft_putchar_fd_pf(char c, int fd)
{
	int i;

	i = 0;
	i = i + write(fd, &c, 1);
	return (i);
}

/* %u ft_undecimal_fd */

/* %x ft_puthex_fd */

/* %X ft_putheX_fd */

/* %p ft_putpointer_fd */