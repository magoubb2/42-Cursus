/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/22 11:48:52 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* Function that convert each variable type */
static int convert(va_list args, const char place_holder)
{
	if (place_holder == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (place_holder == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (place_holder == 'i' || place_holder == 'd')
		return (ft_putnbr_pf(va_arg(args, int), 1));
	else if (place_holder == 'u')
		return (ft_putnbr_pf(va_arg(args, unsigned int), 0));
	else if (place_holder == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (place_holder == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (place_holder == 'p')
		return(ft_pointer(va_arg(args, void *)));
	else if (place_holder == '%')
		return (ft_putchar_pf('%'));
	return (0);
}

/* Function that execute */
int ft_printf(const char *format, ...)
{
	int i;
	int print;
	int conv;
	va_list args;
	
	i = -1;
	print = 0;
	va_start(args, format);
	while (format[++i])
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
	}
	va_end(args);
	return (print);
}

int main(void)
{
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
	ft_printf("mine: %%\n");
	// printf("real: %%\n");
}
