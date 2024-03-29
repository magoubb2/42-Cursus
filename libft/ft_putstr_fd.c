/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:40:20 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 17:14:50 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}

// int main(int argc, char **argv)
// {
// (void)argc;
// ft_putstr_fd("hello", (int)atoi(*argv));
// ft_putstr_fd("hello", open("test_fd", O_WRONLY));
// }