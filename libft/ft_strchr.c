/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:58:46 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/11 11:53:52 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If the character is found in the given string we return the address of the
// character found else we return NULL.
char *ft_strchr(const char *s, int c)
{
    int i;
    char character;
    
    i = 0;
    character = c;
    
    while (s[i] != '\0')
    {
        if (s[i] == character)
            return ((char *)&s[i]);
        i++;
    }
    if (character == '\0')
        return ((char *)&s[i]);
    return (0);
}


// int main(void)
// {
//     int c = '\0';
//     const char str[] = "oellolollmao\0blabla";
//     char *ptr = ft_strchr(str, c);
    
//     printf("mine: %s\n", ft_strchr(str, c));
//     printf("real: %s\n", strchr(str, c));
//     // if (ptr != NULL) 
//     //     printf("Found 'o' at position: %ld\n", ptr - str);
// }