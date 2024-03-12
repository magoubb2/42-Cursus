/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_holder_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/12 09:53:18 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* %c ft_putchar_fd_pf */
size_t	ft_putchar_fd_pf(char c, int fd)
{
	int i;

	i = 0;
	i = i + write(fd, &c, 1);
	return (i);
}

/* %s ft_putstr_fd_pf */
size_t	ft_putstr_fd_pf(char *s, int fd)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(fd, s, ft_strlen(s)));
}

/* %i && %d ft_putnbr_fd_pf */
size_t	ft_putnbr_fd_pf(int n, int fd)
{
	int		i;
	char	*nb;

	nb = "0123456789";
	i = 0;
	if (n == INT_MIN)
	{
		i = i + write(fd, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		i = i + write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		i = i + ft_putnbr_fd_pf(n / 10, fd);
	i = i + write(fd, &nb[n % 10], 1);
	return (i);
}

/* %u ft_undecimal_fd */
size_t	ft_unsigned_fd_pf(unsigned int n, int fd)
{
	int		i;
	char	*nb;

	nb = "0123456789";
	i = 0;
	if (n > 9)
		i = i + ft_putnbr_fd_pf(n / 10, fd);
	i = i + write(fd, &nb[n % 10], 1);
	return (i);
}



/* %x ft_puthex_fd */
size_t	ft_puthex_min(unsigned long n)
{
	int i;

	i = 0;
	if (n > 9)
	{
		if (n < 16)
			i = i + ft_putchar_fd_pf((n + 87), 1);
		else
		{
			i = i + ft_puthex_min(n / 16);
			i = i + ft_puthex_min(n % 16);
		}
	}
	else
		i = i + ft_putchar_fd_pf((n + 48), 1);
	return (i);
}

/* %X ft_putheX_fd */
size_t	ft_puthex_maj(unsigned long n)
{
	int i;

	i = 0;
	if (n > 9)
	{
		if (n < 16)
			i = i + ft_putchar_fd_pf((n + 55), 1);
		else
		{
			i = i + ft_puthex_maj(n / 16);
			i = i + ft_puthex_maj(n % 16);
		}
	}
	else
		i = i + ft_putchar_fd_pf((n + 48), 1);
	return (i);
}

/* %p ft_putpointer_fd */