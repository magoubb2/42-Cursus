/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:06 by margueriteb       #+#    #+#             */
/*   Updated: 2024/03/23 17:49:21 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>

typedef struct s_data
{
    int fd[2];
    int infile;
    int outfile;
    pid_t pid_cmd1;
    pid_t pid_cmd2;
    char *path;
    char **path_to_cmd;
    char **cmd_args;
    char *cmd;
}   t_data;

#endif