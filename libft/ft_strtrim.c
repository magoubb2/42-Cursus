/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:26:05 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/19 14:53:29 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1). Find the position of (start) by skiping (set) using ft_strchr.
// 2). Find the position of (end) by starting end at the end of (s1) and then
//	   skiping (set) using ft_strchr.
// 3). Allocate space for the (new_str) by substracting (start) to (end).
// 4). Copy from (s1[start]) to (new_str[i]).
// 5). return (new_str).
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		str_len;
	char	*new_str;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new_str = (char *)malloc(sizeof(char) * (end - start) + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (start <= end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("abc hello  world abc lol abc", "abc"));
// }