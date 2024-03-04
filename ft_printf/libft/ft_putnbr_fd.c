/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:44:35 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/20 11:54:36 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nb;

	nb = "0123456789";
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &nb[n % 10], 1);
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     ft_putnbr_fd(-12345, (int)atoi(*argv));
//     ft_putnbr_fd(12345, open("test_fd", O_WRONLY));
// }