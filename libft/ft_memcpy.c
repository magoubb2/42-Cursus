/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:02:21 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/12 11:27:14 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    const char *s;
    char *d;

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

// int main(void)
// {
//     const char src[] = "hello world";
//     char dest[20];

//     ft_memcpy(dest, src, sizeof(src));
//     printf("mine: %s\n", dest);
//     ft_memcpy(dest, src, sizeof(src));
//     printf("real: %s\n", dest);
// }