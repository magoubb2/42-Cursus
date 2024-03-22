/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:02:21 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/25 13:12:19 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	if (!src || !dest)
		return (dest);
	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
//     const char src[] = "hello world";
//     char dest[20];

//     // ft_memcpy(dest, NULL, sizeof(src));
//     // printf("mine: %s\n", dest);
//     memcpy(dest, NULL, sizeof(src));
//     printf("real: %s\n", dest);
// }