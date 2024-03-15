/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/15 14:20:42 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* NEED TO HANDLE ERROR -> PRINTF SHOULD RETURN -1 IF IT ENCOUNTERS AN ERROR */

/* Function that convert each variable type */
static int convert(va_list args, const char place_holder)
{
	// %c -> ft_putchar_pf
	if (place_holder == 'c')
		// Convert the place holder for a char.
		return (ft_putchar_pf(va_arg(args, int)));
	// %s -> ft_putstr_pf
	else if (place_holder == 's')
		// Convert the place holder for a string.
		return (ft_putstr_pf(va_arg(args, char *)));
	// %i -> ft_putnbr_pf || %d -> ft_putnbr_pf
	else if (place_holder == 'i' || place_holder == 'd')
		// Convert the place holder for a int.
		return (ft_putnbr_pf(va_arg(args, int), 1));
	// %u -> ft_putnbr_pf
	else if (place_holder == 'u')
		// Convert the place holder for a unsigned int.
		return (ft_putnbr_pf(va_arg(args, unsigned int), 0));
	// %x -> ft_puthex
	else if (place_holder == 'x')
		// Convert the place holder for a integer as an hexadecimal in lower case.
		return (ft_puthex(va_arg(args, unsigned int), 0));
	// %X -> ft_puthex
	else if (place_holder == 'X')
		// Convert the place holder for a integer as an hexadecimal in upper case.
		return (ft_puthex(va_arg(args, unsigned int), 1));
	// %p -> ft_putpointer_pf
	else if (place_holder == 'p')
		// Convert the place holder for a pointer's address
		return(ft_pointer(va_arg(args, void *)));
	else if (place_holder == '%')
		return (ft_putchar_pf('%'));
	else
		return (-1);
	return (0);
}


/* Function that execute */
int ft_printf(const char *format, ...)
{
	int i;
	int print;
	int conv;
	va_list args;
	
	i = 0;
	print = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			conv = convert(args, format[i + 1]);
			if (conv == -1)
				return (-1);
			print = print + conv;
			i++;
		}
		else
			print = print + ft_putchar_pf(format[i]);
		if (print == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (print);
}

// int main(void)
// {
	// char *str = "hello world";
	// char c = 'a';
	// int i = 34;
	// int ui = -1;
	// int x = -10;
	
	// ft_printf("test\n");
	// ft_printf(" [%s] ", str);
	// ft_printf("\n");
	// ft_printf("char: [%c]\n", c);
	// ft_printf("\n");
	// ft_printf("int: [%i]\n", i);
	// ft_printf("\n");
	// ft_printf("mine unsigned int: [%u]\n", ui);
	// printf("real unsigned int: [%u]\n", ui);
	// ft_printf("\n");
	// printf("real hexadecimal x: [%x]\n", x);
	// printf("real hexadecimal x: [%X]\n", x);
	// ft_printf("my hexadecimal x: [%x]\n", x);
	// ft_printf("my hexadecimal x: [%X]\n", x);
	// printf("\n");
	// printf("real pointer: [%p]\n", "hello");
	// ft_printf("my pointer: [%p]\n", "hello");
	// // printf("real pointer: [%p]\n", LONG_MIN);
	// // ft_printf("my pointer: [%p]\n", LONG_MIN);
	// ft_printf("\n");
	// printf("%p\n", "");
	// ft_printf("%p\n", "");
	// ft_printf("\n");
	// ft_printf("mine test: %%\n");
	// printf("real test: %%\n");
	// ft_printf("mine: %%c", c);
	// printf("real: %%c", c);
// }
