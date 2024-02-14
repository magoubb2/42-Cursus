
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:14:25 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/14 13:07:12 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *sub_str;

	i = 0;
	j = 0;
	sub_str = (char *)malloc((sizeof(char)) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = start;
	while (j != len)
	{
		sub_str[j] = s[i];
		i++;
		j++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}

// int main(void)
// {
// 	// printf("%s\n", ft_substr("hello world", 5, 5));
// 	printf("%s\n", ft_substr("hello world", 20, 7));
// 	// printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 400, 20));
// }