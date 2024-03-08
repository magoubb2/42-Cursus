/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/08 14:28:37 by marbaron         ###   ########.fr       */
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
	if (place_holder == 's')
		// Convert the place holder for a string.
		ft_putstr_fd_pf(va_arg(args, char *), 1);
	// %i -> ft_putnbr_fd || %d -> ft_putnbr_fd
	if (place_holder == 'i' || place_holder == 'd')
		// Convert the place holder for a int.
		ft_putnbr_fd_pf(va_arg(args, int), 1);
	// %u -> ft_undecimal_fd
	if (place_holder == 'u')
		// Convert the place holder for a unsigned int.
		ft_unsigned_fd_pf(va_arg(args, unsigned int), 1);
	// %x -> ft_puthex_fd
	if (place_holder == 'x')
		// Convert the place holder for a integer as an hexadecimal in lower case.
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	// %X -> ft_putheX_fd
	if (place_holder == 'X')
		// Convert the place holder for a integer as an hexadecimal in upper case.
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	// %p -> ft_putpointer_fd
	// if (place_holder == 'p')
		// Convert the place holder for a pointer's address
	if (place_holder == '%')
		ft_putchar_fd_pf('%', 1);
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
		{
			// convert the place holder.
			print = print + convert(args, format[i + 1]);
			i++;
		}
		else
			print = print + ft_putchar_fd_pf(format[i], 1);
		i++;
	}
	va_end(args);
	return (print);
}

// int main(void)
// {
// 	char *str = "hello";
// 	char c = 'c';
// 	int i = 34;
// 	int ui = -34;
// 	int x = 11;
	
// 	ft_printf("string: [%s]\n", str);
// 	ft_printf("\n");
// 	ft_printf("char: [%c]\n", c);
// 	ft_printf("\n");
// 	ft_printf("int: [%i]\n", i);
// 	ft_printf("\n");
// 	ft_printf("mine unsigned int: [%u]\n", ui);
// 	ft_printf("\n");
// 	printf("real unsigned int: [%u]\n", ui);
// 	ft_printf("\n");
// 	ft_printf("hexadecimal x: [%x]\n", x);
// 	ft_printf("\n");
// 	ft_printf("hexadecimal X: [%X]\n", x);
// }