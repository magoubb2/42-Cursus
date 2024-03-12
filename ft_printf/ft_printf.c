/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/12 16:32:47 by margueriteb      ###   ########.fr       */
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
	if (place_holder == 'p')
		// Convert the place holder for a pointer's address
		return(ft_pointer(va_arg(args, void *)));
	else if (place_holder == '%')
		return (ft_putchar_pf('%'));
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
			print = print + ft_putchar_pf(format[i]);
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
// 	char *str = "hello world";
// 	char c = 'c';
// 	int i = 34;
// 	int ui = -1;
// 	int x = -10;
	
// 	ft_printf("test\n");
// 	ft_printf(" [%s] ", str);
// 	ft_printf("\n");
// 	ft_printf("char: [%c]\n", c);
// 	ft_printf("\n");
// 	ft_printf("int: [%i]\n", i);
// 	ft_printf("\n");
// 	ft_printf("mine unsigned int: [%u]\n", ui);
// 	printf("real unsigned int: [%u]\n", ui);
// 	ft_printf("\n");
// 	printf("real hexadecimal x: [%x]\n", x);
// 	printf("real hexadecimal x: [%X]\n", x);
// 	ft_printf("my hexadecimal x: [%x]\n", x);
// 	ft_printf("my hexadecimal x: [%X]\n", x);
// 	printf("\n");
// 	printf("real pointer: [%p]\n", "hello");
// 	ft_printf("my pointer: [%p]\n", "hello");
// 	// printf("real pointer: [%p]\n", LONG_MIN);
// 	// ft_printf("my pointer: [%p]\n", LONG_MIN);
// 	ft_printf("\n");
// 	printf("%p\n", "");
// 	ft_printf("%p\n", "");
// 	ft_printf("\n");
// 	ft_printf("mine test: %%\n");
// 	printf("real test: %%\n");
// }

int	main()
{
	char c = 'a';
	char *s = NULL;
	int i = 2147483647;
	int d = -2147483648;
	int x = 2147483647;
	int X = -2147483648;
	void *p = "hello u";
	unsigned int u = 4294967295;

	// basic tests
	ft_printf("*********TEST RESULT*********\n");
	ft_printf("c = %c\ni = %i\nd = %d\ns = %s\nx = %x\nX = %X\np = %p\nu = %u\n%% = %%\n\n", c, i, d, s, x, X, p, u);

	printf("real c = %c\n", c);
	printf("real i = %i\n", i);
	printf("real d = %d\n", d);
	printf("real s = %s\n", s);
	printf("real x = %x\n", x);
	printf("real X = %X\n", X);
	printf("real p = %p\n", p);
	printf("real u = %u\n", u);
	printf("real %% = %%\n\n");

	// printf returns the lengtht of the string it printed
	printf("*****printf returns the length of what it prints*****\n");

	int str_len = printf("(char) %c\n", c);
	int my_str_len = ft_printf("(char) %c\n", c);
	printf("real return = %i\n", str_len);
	ft_printf("my return = %i\n\n", my_str_len);

	int str_len1 = printf("(hexa) %x\n", x);
	int my_str_len1 = ft_printf("(hexa) %x\n", x);
	printf("real return = %i\n", str_len1);
	ft_printf("my return = %i\n\n", my_str_len1);
	
	int str_len7 = printf("(HEXA) %X\n", X);
	int my_str_len7 = ft_printf("(HEXA) %X\n", X);
	printf("real return = %i\n", str_len7);
	ft_printf("my return = %i\n\n", my_str_len7);

	int str_len2 = printf("(pointer) %p\n", p);
	int my_str_len2 = ft_printf("(pointer) %p\n", p);
	printf("real return = %i\n", str_len2);
	ft_printf("my return = %i\n\n", my_str_len2);

	int str_len3 = printf("(string) %s\n", s);
	int my_str_len3 = ft_printf("(string) %s\n", s);
	printf("real return = %i\n", str_len3);
	ft_printf("my return = %i\n\n", my_str_len3);

	int str_len4 = printf("(int) %i\n", i);
	int my_str_len4 = ft_printf("(int) %i\n", i);
	printf("real return = %i\n", str_len4);
	ft_printf("my return = %i\n\n", my_str_len4);

	int str_len8 = printf("(d) %d\n", d);
	int my_str_len8 = ft_printf("(d) %d\n", d);
	printf("real return = %i\n", str_len8);
	ft_printf("my return = %i\n\n", my_str_len8);

	int str_len5 = printf("(percent) %%\n");
	int my_str_len5 = ft_printf("(percent) %%\n");
	printf("real return = %i\n", str_len5);
	ft_printf("my return = %i\n\n", my_str_len5);

	int str_len6 = printf("(u) %u\n", u);
	int my_str_len6 = ft_printf("(u) %u\n", u);
	printf("real return = %i\n", str_len6);
	ft_printf("my return = %i\n\n", my_str_len6);
}