/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:01 by margueriteb       #+#    #+#             */
/*   Updated: 2024/04/01 15:13:16 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Function that get's the current command.
static char *get_current_cmd(char **current_path, char *current_cmd)
{
    char *tmp;
    char *cmd;

    while (*current_path)
    {
        tmp = ft_split(*current_path, '/');
        cmd = ft_strjoin(tmp, current_cmd);
    }
    return (cmd);
}

// First command.
static void first_child(t_data data, char **argv, char **env)
{
    // (void)data;
    // (void)argv;
    (void)env;
    // Replace standart output with the with output file
    dup2(data.fd[1], 1);
    // Close unused file.
    ft_printf("current arg\n");
    close(data.fd[0]);
    // Replace standart input with the infile file.
    dup2(data.infile, 0);
    data.cmd_args = ft_split(argv[2], ' ');
    data.cmd = get_current_cmd(data.path, data.cmd_args[0]);
    // ft_printf("current arg: %s\n", data.cmd_args[1]);
    ft_printf("%s\n", data.cmd);
    // Execute the command.
    // execve()
}

// Returns the value of env.
static char *path(char **env)
{
    int i;

    i = 0;
    // Loop until the end of the env array is reached. Loop through the array 
    // of string untils finding the one starting with "PATH".
    while (env[i] != NULL)
    {
        // If "PATH" is found, return the current str of env.
        if (ft_strncmp("PATH", env[i], 4) == 0)
            return(env[i]);
        // Move to the next str in the array.
        i++;
    }
    // Else return NULL.
    return (NULL);
}

int main(int argc, char **argv, char **env) 
{

    t_data data;
    
    // if (argc != 5)
        // return error

    // 1). Check for errors.
    
    // 2). Initialise infile.
    // Open argv[1] which is the first fd (in this case "infile"). Open it in read
    // only mode.
    data.infile = open(argv[1], O_RDONLY);
    // 3). Initialise outfile.
    // Open argv[argc - 1] which mean the last fd (in this case, "outfile").
    // Using the open function we want to write and read (O_RDWR) in this file and 
    // create it if it does not exist(O_CREAT). And these are the permission 0000644.
    data.outfile = open(argv[argc - 1], O_CREAT | O_RDWR, 0000644);
    // 4). Create necessary pipe.
    pipe(data.fd);
    // 5). Get the path.
    // Use path to get the path.
    data.path = path(env);
    ft_printf("path: %s\n", data.path);
    // 6).Get the command path.
    // Check each path directory for the current command.
    data.get_directory = ft_split(data.path, ':');
    ft_printf("get_directory: %s\n", data.get_directory[0]);
    // 7). First child process.(fork)
    // New child process.
    data.pid_cmd1 = fork();
    ft_printf("fork pid_cmd1: %i\n", data.pid_cmd1);
    if (data.pid_cmd1 == 0)
        // Execute the first command.
        first_child(data, argv, env);
    // 8).Second child process.(fork)
    // data.pid_cmd2 = fork();
        // Execute second command.
    
    // 9).
    // Close pipe.
    // Wait for first child.
    // Wait for second child.
}