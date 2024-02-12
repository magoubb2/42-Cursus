/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:22:47 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/12 11:27:18 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlcpy copies up to dstsize - 1 character (to avoid buff overflow) from 
// string source to string destination.
size_t ft_strlcpy(char *dst, const char *src, size_t destsize)
{
    size_t i;
    size_t src_len;
    
    i = 0;
    src_len = ft_strlen(src);
    if (!src || !dst)
        return (0);
    if (destsize != 0)
    {
        while (i < (destsize - 1) && src[i])
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (src_len);
}
