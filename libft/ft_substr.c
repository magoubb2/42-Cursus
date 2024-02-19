/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:14:25 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/19 15:01:06 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub_str;

	i = 0;
	j = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (!s)
		return (NULL);
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
// 	printf("%s\n", ft_substr("", 1, 1));
// 	// printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 400, 20));
// }