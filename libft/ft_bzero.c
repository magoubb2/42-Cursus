/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:21:49 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/07 10:45:29 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Same as memset but only with zero's.
void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *str;
    
    i = 0;
    str = s;
    while (i < n)
    {
        str[i] = 0;
        i++;
    }
}

// int main(void)
// {
//     char buffer[10];
//     size_t i = 0;

//     ft_bzero(buffer, sizeof(buffer));
//     // bzero(buffer, sizeof(buffer));
    
//     while (i < sizeof(buffer))
//     {
//         printf("%i", buffer[i]);
//         i++;
//     }
// }