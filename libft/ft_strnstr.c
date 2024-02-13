
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:11:28 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/12 14:40:52 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    const char *n;
    const char *h;

    if (needle[0] == '\0' && len == 0)
        return ((char *)haystack);
    if (haystack[0] == '\0' && needle[0] == '\0')
        return ((char *)haystack);
    while (*haystack && len)
    {
        if (len < ft_strlen(needle))
            return (NULL);
        h = haystack;
        n = needle;
        while (*h == *n && *n && *h && len)
        {
            h++;
            n++;
        }
        if (*n == '\0')
            return ((char *)haystack);
        haystack++;
        len--;
    }
    return (NULL);
}

// int main() {

    
//     printf("mine: %s\n", ft_strnstr("aaabcabcd", "abcd", 8));
//     printf("real: %s\n", strnstr("aaabcabcd", "abcd", 8));
//     return 0;
// }