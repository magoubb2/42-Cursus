/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:02:21 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/20 16:51:09 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	i = 0;
	s = src;
	d = dest;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int main(void)
{
    const char src[] = "hello world";
    char dest[20];

    // ft_memcpy(dest, NULL, sizeof(src));
    // printf("mine: %s\n", dest);
    memcpy(dest, NULL, sizeof(src));
    printf("real: %s\n", dest);
}