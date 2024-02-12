/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:22:02 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/12 11:27:15 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// same as memcpy but also check if the two string overlap and make sure it
// doesn't mess things up. It does so by checking if s starts before the 
// destination memory block d. And if the destination memory block d ends
// before the end of the source memory block s. if these two are true then
// we copie starting from the end of s.
void *ft_memmove(void *dest, const void *src, size_t len)
{
    size_t i;
    const char *s;
    char *d;
    
    if (!src && !dest)
        return (NULL);
    s = src;
    d = dest;
    if (s < d && (s + len) > d)
    {
        i = len;
        while (i > 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }
    }
    else
    {
        i = 0;
        while (i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}


// int main(void)
// {
//     char dest[] = "hello";
//     char src[] = "yolos";
//     size_t n = 10;
//     char *str = ft_memmove((void *)dest, (const void *)src, n);
//     // char *str1 = memmove((void *)dest, (const void *)src, n);

//     printf("%s\n", str);
//     // printf("%s\n", str1);
// }