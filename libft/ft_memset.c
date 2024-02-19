/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:29:50 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/19 14:56:52 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_memset function us used to fill a block of memory with a particular
// value. the function returns a (void *). then function as three variables
// in it's parameters. 1) void *b: a pointer to the block of memory to fill.
// 2). int value: The value to be set. 3). num: The number of bytes to be set
// to the value. We initialize two new variable of type unsigned char, ptr
// and value. We to copy the value on every position inside of the array.
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	value;

	i = 0;
	value = (unsigned char)c;
	ptr = b;
	while (i < len)
	{
		ptr[i] = value;
		i++;
	}
	return (b);
}

// int main(void)
// {
//     char buffer[10];
//     size_t i = 0;
//     ft_memset(buffer, 'a', sizeof(buffer));
//     // memset(buffer, 'a', sizeof(buffer));

//     while (i < sizeof(buffer))
//     {
//         printf("[%zu] = %c\n", i, buffer[i]);
//         i++;
//     }
// }