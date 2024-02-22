/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:16:37 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 16:57:27 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - (int)str2[i]);
		i++;
	}
	return (0);
}

// int main() {
//     const char str1[] = "hello";
//     const char str2[] = "helli";
//     size_t n = 5; // Number of bytes to compare

//     printf("%i\n", ft_memcmp(str1, str2, n));

//     return 0;
// }