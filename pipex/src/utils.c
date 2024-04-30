/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:56:48 by margueriteb       #+#    #+#             */
/*   Updated: 2024/04/15 12:13:04 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>

int    print_msg(char *msg)
{
    ft_printf("%s\n", msg);
    return(1);
}

void    error_msg(char *msg)
{
    // ft_printf(RED);
    perror(msg);
    // Exit failure.
    exit(1);
}

void free_parents(t_data *data)
{
    int i;

    i = 0;
    close(data->infile);
    close(data->outfile);
    while (data->get_directory[i])
    {
        free(data->get_directory[i]);
        i++;
    }
    free(data->get_directory);
}

void free_child(t_data *data)
{
    int i;

    i = 0;
    while (data->cmd_args[i])
    {
        free(data->cmd_args[i]);
        i++;
    }
    free(data->cmd_args);
    free(data->cmd);
}