/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:38 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/12 11:27:17 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Get the len of dest and also check that we don't go beyond destsize.
// Then we append src to dest until NULL terminated or until reaching destsize.
size_t ft_strlcat(char *dest, const char *src, size_t destsize)
{
    size_t i_src;
    size_t i_dest;

    i_src = 0;
    i_dest = 0;
    while (dest[i_dest] && i_dest < destsize)
        i_dest++;
    while (src[i_src] && (i_dest + i_src + 1) < destsize)
    {
        dest[i_dest + i_src] = src[i_src];
        i_src++;
    }
    if (i_dest != destsize)
        dest[i_dest + i_src] = '\0';
    return (i_dest + ft_strlen(src));
}

// int main() 
// {
//     char dest[20] = "Hello";
//     const char *src = " world!";
//     size_t destsize = sizeof(dest);
//     printf("%zu\n", ft_strlcat(dest, src, destsize));

//     return 0;
// }