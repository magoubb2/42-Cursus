/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/04 15:02:51 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Function that convert each variable type */
static int convert(va_list args, const char format)
{
	// %s -> ft_putstr_fd
	
	// %c -> ft_putchar_fd
	
	// %i -> ft_putnbr_fd
	
	// %u -> ft_undecimal_fd
	
	// %x -> ft_puthex_fd
	
	// %X -> ft_putheX_fd
	
	// %p -> ft_putpointer_fd
}

/* Function that execute */
int ft_printf(const char *format, ...)
{
	
}