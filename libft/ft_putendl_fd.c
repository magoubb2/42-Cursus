/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:42:38 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 17:14:46 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
// int main(int argc, char **argv)
// {
//     (void)argc;
//     ft_putnbr_fd(-12345, (int)atoi(*argv));
//     ft_putstr_fd("hello", open("test_fd", O_WRONLY));
// }