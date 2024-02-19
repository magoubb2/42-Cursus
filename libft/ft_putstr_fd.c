/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:40:20 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/19 13:15:42 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     ft_putstr_fd("hello", (int)atoi(*argv));
// }