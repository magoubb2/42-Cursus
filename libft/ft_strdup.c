/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:44:10 by marbaron          #+#    #+#             */
/*   Updated: 2024/02/19 14:59:45 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocate space to copy a copy of the (s1) string. And then returns it.
char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*copy;

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
