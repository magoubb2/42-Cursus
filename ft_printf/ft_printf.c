/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/12 10:45:43 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Function that convert each variable type */
static int convert(va_list args, const char place_holder)
{
	// %c -> ft_putchar_fd
	if (place_holder == 'c')
		// Convert the place holder for a char.
		return (ft_putchar_fd_pf(va_arg(args, int), 1));
	// %s -> ft_putstr_fd
	else if (place_holder == 's')
		// Convert the place holder for a string.
		return (ft_putstr_fd_pf(va_arg(args, char *), 1));
	// %i -> ft_putnbr_fd || %d -> ft_putnbr_fd
	else if (place_holder == 'i' || place_holder == 'd')
		// Convert the place holder for a int.
		return (ft_putnbr_fd_pf(va_arg(args, int), 1));
	// %u -> ft_undecimal_fd
	else if (place_holder == 'u')
		// Convert the place holder for a unsigned int.
		return (ft_unsigned_fd_pf(va_arg(args, unsigned int), 1));
	// %x -> ft_puthex_fd
	else if (place_holder == 'x')
		// Convert the place holder for a integer as an hexadecimal in lower case.
		return (ft_puthex(va_arg(args, unsigned int), 0));
	// %X -> ft_putheX_fd
	else if (place_holder == 'X')
		// Convert the place holder for a integer as an hexadecimal in upper case.
		return (ft_puthex(va_arg(args, unsigned int), 1));
	// %p -> ft_putpointer_fd
	// if (place_holder == 'p')
		// Convert the place holder for a pointer's address
	else if (place_holder == '%')
		return (ft_putchar_fd_pf('%', 1));
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
	print = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			// convert the place holder.
			print = print + convert(args, format[i + 1]);
			i++;
		}
		else
			print = print + ft_putchar_fd_pf(format[i], 1);
		i++;
	}
	// printf("\n");
	// printf("i: %i\n", i);
	// printf("\n");
	// printf("print: %i\n", print);
	// printf("\n");
	va_end(args);
	return (print);
}

// int main(void)
// {
	// char *str = "hello";
	// char c = 'c';
	// int i = 34;
	// int ui = -34;
	// int x = -10;
	
	// ft_printf("test\n");
	// ft_printf(" [%s] ", str);
	// ft_printf("string: [%s]\n", str);
	// ft_printf("\n");
	// ft_printf("char: [%c]\n", c);
	// ft_printf("\n");
	// ft_printf("int: [%i]\n", i);
	// ft_printf("\n");
	// ft_printf("mine unsigned int: [%u]\n", ui);
	// ft_printf("\n");
	// ft_printf("\n");
	// printf("real hexadecimal x: [%lx]\n", LONG_MAX);
	// printf("real hexadecimal X: [%lX]\n", LONG_MIN);
	// ft_printf("my hexadecimal x: [%x]\n", LONG_MAX);
	// ft_printf("my hexadecimal X: [%X]\n", LONG_MIN);
	// printf("\n");
	// ft_printf("%X", LONG_MAX);
	// printf("\n");
	// ft_printf("\n");
	// ft_printf("mine test: %%\n");
	// printf("real test: %%\n");
// }