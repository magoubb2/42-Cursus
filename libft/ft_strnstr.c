
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

// 1). Check for empty (needle) str and (len) is 0, if true return (haystack).
// 2). Check if both (needle) and (haystack) are empty, if true return
//     (haystack).
// 3). While (haystack) and (len) is not == to 0,
//          1). Check if (len) is then len of (needle), if true, return
//              NULL.
//          2). Cast (haystack -> h) and (needle -> n) to const char *.
//          3). while (*h) == (*n) and (*h != '\0') and (*n != '\0) and 
//              len != 0 if true, we increment (h) and (n).
//          4). Check if (*n) == '\0' if true, return haystack.
//          5). Increment (haystack) and decrement (len).
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    const char *n;
    const char *h;

    if (needle[0] == '\0' && len == 0)
        return ((char *)haystack);
    if (haystack[0] == '\0' && needle[0] == '\0')
        return ((char *)haystack);
    while (*haystack && len != 0)
    {
        if (len < ft_strlen(needle))
            return (NULL);
        h = haystack;
        n = needle;
        while (*h == *n && *n && *h && len != 0)
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