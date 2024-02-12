/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:10:05 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/09 14:06:09 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char character;
    const unsigned char *str;
    
    i = 0;
    character = c;
    str = s;
    while (i < n)
    {
        if (str[i] == character)
            return ((void *) &s[i]);
        i++;   
    }
    return (0);
}

// int main() {
//     const char str[] = "Hell, wrld!";
//     int character = 'o';
//     size_t n = strlen(str); // Get the length of the string

//     // Search for the first occurrence of the character in the string
//     void *ptr = ft_memchr(str, character, n);

//     if (ptr != NULL) {
//         printf("Found '%c' at position: %ld\n", character, (char *)ptr - str);
//     } else {
//         printf("Character not found.\n");
//     }

//     return 0;
// }