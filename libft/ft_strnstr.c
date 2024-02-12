/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:11:28 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/10 00:05:10 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    const char *n;
    const char *h;

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
//     const char *haystack = "Hello,lol lol world! lol ";
//     const char *needle = "";
//     size_t len = 13; // Length of haystack excluding null terminator

//     // Call ft_strnstr
//     char *result = ft_strnstr(haystack, needle, len);

//     // Check if needle was found
//     if (result != NULL) {
//         printf("'%s' found at index %ld in '%s'\n", needle, result - haystack, haystack);
//     } else {
//         printf("'%s' not found in '%s'\n", needle, haystack);
//     }

//     return 0;
// }