/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_holder_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/12 11:39:52 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* %c ft_putchar_pf */
size_t	ft_putchar_pf(char c)
{
	int i;

	i = 0;
	i = i + write(1, &c, 1);
	return (i);
}

/* %s ft_putstr_pf */
size_t	ft_putstr_pf(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}

/* %i, %d && %u ft_putnbr_pf */
size_t	ft_putnbr_pf(long long n, int not_unsigned)
{
	int		i;
	char	*nb;

	nb = "0123456789";
	i = 0;
	if (n == INT_MIN && not_unsigned)
	{
		i = i + write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0 && not_unsigned)
	{
		i = i + write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		i = i + ft_putnbr_pf(n / 10, not_unsigned);
	i = i + write(1, &nb[n % 10], 1);
	return (i);
}

/* %x ft_puthex */
/* %X ft_putheX */
size_t	ft_puthex(unsigned int n, int letter)
{
	int i;

	i = 0;
	if (n > 9)
	{
		if (n < 16)
		{
			// If letter is true(0) -> is uppercase
			if (letter)
				i = i + ft_putchar_pf((n + 55));
			// If letter is false(1) -> is lowercase
			else if (!letter)
				i = i + ft_putchar_pf((n + 87));
		}
		else
		{
			i = i + ft_puthex(n / 16, letter);
			i = i + ft_puthex(n % 16, letter);
		}
	}
	else
		i = i + ft_putchar_pf((n + 48));
	return (i);
}

/* %p ft_putpointer_pf */