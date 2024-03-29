/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:26:05 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 17:15:39 by marbaron         ###   ########.fr       */
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
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim(NULL, NULL));
// }