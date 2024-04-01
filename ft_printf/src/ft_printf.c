/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/04/01 13:56:35 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	convert(va_list args, const char place_holder)
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
		return (ft_pointer(va_arg(args, void *)));
	else if (place_holder == '%')
		return (ft_putchar_pf('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print;
	int		conv;
	va_list	args;

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
