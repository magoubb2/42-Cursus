/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:56:48 by margueriteb       #+#    #+#             */
/*   Updated: 2024/04/05 10:03:40 by margueriteb      ###   ########.fr       */
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