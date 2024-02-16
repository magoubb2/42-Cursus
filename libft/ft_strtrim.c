/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:26:05 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/16 14:05:37 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int start;
	int end;
	int str_len;
	char *new_str;

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