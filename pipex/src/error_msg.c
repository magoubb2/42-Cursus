/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:56:48 by margueriteb       #+#    #+#             */
/*   Updated: 2024/04/05 09:10:01 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int    print_msg(char *msg)
{
    ft_printf("%s\n", msg);
    return (1);
}

void    error_msg(char *msg)
{
    perror(msg);
    exit(1);
} 