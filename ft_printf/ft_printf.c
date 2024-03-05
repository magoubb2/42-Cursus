/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/05 11:01:56 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Function that convert each variable type */
static int convert(va_list args, const char place_holder)
{
	(void) args;
	(void) format;
	// %s -> ft_putstr_fd
	if (place_holder == 's')
		// Convert the place holder for a string.
	// %c -> ft_putchar_fd
	if (place_holder == 'c')
		// Convert the place holder for a char.
	// %i -> ft_putnbr_fd || %d -> ft_putnbr_fd
	if (place_holder == 'i' || place_holder == 'd')
		// Convert the place holder for a int.
	// %u -> ft_undecimal_fd
	if (place_holder == 'u')
		// Convert the place holder for a unsigned int.
	// %x -> ft_puthex_fd
	if (place_holder == 'x')
		// Convert the place holder for a integer as an hexadecimal in lower case.
	// %X -> ft_putheX_fd
	if (place_holder == 'X')
		// Convert the place holder for a integer as an hexadecimal in upper case.
	// %p -> ft_putpointer_fd
	if (place_holder == 'p')
		// Convert the place holder for a pointer's address
	return (0);
}

/* Function that execute */
int ft_printf(const char *format, ...)
{
	(void) convert;
	int i;
	int print;
	va_list args;
	
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			// convert the place holder.
			print = print + convert(args, format[i + 1]);
		if (format[i] != '%')
			print = print + ft_putchar_fd_pf(format[i], 1);
		i++;
	}
	va_end(args);
	return (print);
}

int main(void)
{
	ft_printf("hello", 1);
}