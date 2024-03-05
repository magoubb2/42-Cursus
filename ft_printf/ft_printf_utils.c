/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:22 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/05 13:11:25 by marbaron         ###   ########.fr       */
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
		return ;
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
		return ;
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
 ft_putnbr_base(int nbr, char *base)
{
    int base_len;
    
    base_len = ft_strlen(base);
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr = -nbr;
    }
    if (nbr >= base_len)
        ft_putnbr_base(nbr / base_len, base);
    write(1,&base[nbr % base_len], 1);
}


/* %x ft_puthex_fd */

/* %X ft_putheX_fd */

/* %p ft_putpointer_fd */