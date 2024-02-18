/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:14:08 by marbaron          #+#    #+#             */
/*   Updated: 2024/02/18 15:46:57 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
	int i;
	int nb;
	int len;
	char *str;

	nb = n;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	while (n != 0)
	{
		str[len--] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}

int main(void)
{
	printf("%s\n", ft_itoa(12345));
}