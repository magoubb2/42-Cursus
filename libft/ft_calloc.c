/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:37:09 by marbaron          #+#    #+#             */
/*   Updated: 2024/02/20 10:56:59 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	byte_size;
	size_t	*ptr;

	byte_size = count * size;
	ptr = (void *)malloc((byte_size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, byte_size);
	return ((void *)ptr);
}

// int main(void)
// {
// 	int *ptr;
// 	int *ptr1;
// 	// ptr = calloc(1, 1);
// 	// ptr1 = ft_calloc(1, 1);
// 	ptr = calloc(1, 1);
// 	printf("real: %i\n", (int)ptr);
// 	ptr = ft_calloc(1, 1);
// 	printf("mine: %i\n", (int)ptr);
// }