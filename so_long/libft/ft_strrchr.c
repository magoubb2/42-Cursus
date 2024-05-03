/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:15 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 17:10:32 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	character;

	character = c;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == character)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// int main(void)
// {
//     int c = 'o';
//     const char *str = "hello";
//     //  char *ptr = ft_strrchr(str, c);

//     printf("mine: %s\n", ft_strrchr(str, c));
//     printf("real: %s\n", strrchr(str, c));
// }