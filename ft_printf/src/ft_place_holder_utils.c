/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_holder_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/28 14:51:47 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_pf(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr_pf(long long n, int not_unsigned)
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
	if (i == -1)
		return (-1);
	if (n > 9)
		i = i + ft_putnbr_pf(n / 10, not_unsigned);
	if (i == -1)
		return (-1);
	i = i + write(1, &nb[n % 10], 1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_puthex(unsigned long n, int letter)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		if (n < 16)
		{
			if (letter)
				i = i + ft_putchar_pf((n + 55));
			if (!letter)
				i = i + ft_putchar_pf((n + 87));
		}
		else
		{
			i = i + ft_puthex(n / 16, letter);
			if (i == -1)
				return (-1);
			i = i + ft_puthex(n % 16, letter);
			if (i == -1)
				return (-1);
		}
	}
	else
		i = i + ft_putchar_pf((n + 48));
	return (i);
}

int	ft_pointer(void *ptr)
{
	int	i;

	i = 0;
	i = i + write(1, "0x", 2);
	if (i == -1)
		return (-1);
	if (ptr == 0)
	{
		i = i + write(1, "0", 1);
		if (i == -1)
			return (-1);
	}
	else
	{
		i = i + ft_puthex((unsigned long long)ptr, 0);
		if (i == -1)
			return (-1);
	}
	return (i);
}
