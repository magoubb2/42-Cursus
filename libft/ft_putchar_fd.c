/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:39:00 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/20 11:54:08 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     ft_putchar_fd('h', (int)atoi(argv[2]));
//     ft_putstr_fd("hello", open("test_fd", O_WRONLY));
// }