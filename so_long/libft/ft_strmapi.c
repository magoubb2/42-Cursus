/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:44:03 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 17:03:06 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// execute the (f) function for each char in the (s) string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (0);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// char	uppercase_converter(unsigned int index, char c)
// {
// 	(void)index; // Unused parameter (index)
// 	if (c >= 'a' && c <= 'z')
// 		return c - 32;
// 	else
// 		return c;
// }

// int main(void)
// {
//    printf("%s\n", ft_strmapi("hello", uppercase_converter));
// }