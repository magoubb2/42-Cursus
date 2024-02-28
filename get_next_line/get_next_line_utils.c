/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:59:50 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/28 11:50:18 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*copy;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	i = 0;
	copy = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return ((char *)copy);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*full_str;
	int		full_len;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	if (!full_len)
		return (NULL);
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

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	character;

	i = 0;
	character = c;
    if (!s)
        return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == character)
			return (&s[i]);
		i++;
	}
	if (character == '\0')
		return (&s[i]);
	return (0);
}
