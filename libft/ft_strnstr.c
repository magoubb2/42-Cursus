/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:11:28 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/12 14:32:40 by marbaron         ###   ########.fr       */
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
        h = haystack;
        n = needle;
        while (*h == *n && *n != '\0' && len)
        {
            h++;
            n++;
            len--;
        }
        if (*n == '\0')
            return ((char *)haystack);
        haystack++;
        len--;
    }
    return (NULL);
}

// int main() {
//     const char haystack[30] = "aaabcabcd";
//     const char *needle;
//     size_t len = 20; // Length of haystack excluding null terminator

//     printf("mine: %s\n", ft_strnstr(haystack, "abcd", 9));
//     printf("real: %s\n", strnstr(haystack, "abcd", 9));
//     return 0;
// }