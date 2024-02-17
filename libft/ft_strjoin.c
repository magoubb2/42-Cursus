/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:37:19 by marbaron          #+#    #+#             */
/*   Updated: 2024/02/17 11:01:43 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate space for the concatenation of the two strings (s1) and (s2). Then,
// we copy the first string in the new variable (new_str) and then once this
// is done, we start copying the seond one in the (new_str).
char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	char *full_str;
	int full_len;
	int len_s1;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	len_s1 = ft_strlen(s1);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	full_str = (char *)malloc(sizeof(char) * full_len + 1);
	if (!full_str)
		return (NULL);
	while (s1[i])
	{
		full_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		full_str[i++] = s2[j++];
	full_str[i] = '\0';
	return (full_str);
}

// int main(void)
// {
// 	char *strjoin;
// 	const char s1[] = "hello";
// 	const char s2[] = "world";

// 	strjoin = ft_strjoin(s1, s2);
// 	printf("%s\n", strjoin);
// }
