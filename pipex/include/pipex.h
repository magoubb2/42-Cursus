/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:06 by margueriteb       #+#    #+#             */
/*   Updated: 2024/04/06 10:36:33 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../libft/libft.h"

#define ARG_NUM_BAD "The number of argument is not 5. Try again!"
#define INFILE_ERR  "infile"
#define OUTFILE_ERR  "outfile"
#define PIPE_ERR  "pipe"
#define CMD_ERR "command"

typedef struct s_data
{
    int fd[2];
    int infile;
    int outfile;
    pid_t pid_cmd1;
    pid_t pid_cmd2;
    char *path;
    char **get_directory;
    char **cmd_args;
    char *cmd;
}   t_data;

// void first_child(t_data data, char **argv, char **env);
// void second_child(t_data data, char **argv, char **env);
void    error_msg(char *msg);
int     print_msg(char *msg);
void    free_parents(t_data *data);
void    free_child(t_data *data);



#endif