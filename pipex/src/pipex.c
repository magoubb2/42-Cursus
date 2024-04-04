/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:01 by margueriteb       #+#    #+#             */
/*   Updated: 2024/04/04 15:34:41 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Function that get's the current command.
// Search for a command executable in a list of directory(current_path).
static char *get_current_cmd(char **current_path, char *current_cmd)
{
    char *tmp;
    char *cmd;

    // Loop trough each directory path in the current_path array.
    while (*current_path)
    {
        // Add a slash to to the end of current path.
        tmp = ft_strjoin(*current_path, "/");
        // Concatenate the current_cmd to tmp.
        cmd = ft_strjoin(tmp, current_cmd);
        free(tmp);
        // Check if the constructed command path is accessable. It checks if the
        // the file exist and the process has permission to execute it. Using the
        // 0 mode which checks it's existance. 
        if (access(cmd, 0) == 0)
            // if it is, return cmd.
            return (cmd);
        free(cmd);
        // Move to the next directory path.
        current_path++;
    }
    // Return NULL if the cmd is found in none of the path.
    return (NULL);
}

// Second command
static void second_child(t_data data, char **argv, char **env)
{
    // Redirect standard input to read from the read end of the pipe.
    dup2(data.fd[0], 0);
    // Close the write end of the pipe because it is not needed.
    close(data.fd[1]);
    // Redirect standard output to write to the specified output file.
    dup2(data.outfile, 1);
    // Parse the command argument from argv[2]
    data.cmd_args = ft_split(argv[3], ' ');
    data.cmd = get_current_cmd(data.get_directory, data.cmd_args[0]);
    // Execute the command.
    execve(data.cmd, data.cmd_args, env);
}

// First command.
static void first_child(t_data data, char **argv, char **env)
{
    // Replace standart output with the output file
    dup2(data.fd[1], 1);
    // Close unused file.
    close(data.fd[0]);
    // Replace standart input with the infile file.
    dup2(data.infile, 0);
    // Parse the command argument from argv[2]
    data.cmd_args = ft_split(argv[2], ' ');
    data.cmd = get_current_cmd(data.get_directory, data.cmd_args[0]);
    // Execute the command.
    execve(data.cmd, data.cmd_args, env);
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
            return(env[i] + 5);
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
    data.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
    // 4). Create necessary pipe.
    pipe(data.fd);
    // 5). Get the path.
    // Use path to get the path.
    data.path = path(env);
    // 6).Get the command path.
    // Check each path directory for the current command.
    data.get_directory = ft_split(data.path, ':');
    // 7). First child process.(fork)
    // New child process.
    data.pid_cmd1 = fork();
    if (data.pid_cmd1 == 0)
        // Execute the first command.
        first_child(data, argv, env);
    // 8).Second child process.(fork)
    data.pid_cmd2 = fork();
        // Execute second command.
        second_child(data, argv, env);
    // 9).
    // Close pipe.
    close(data.fd[0]);
    close(data.fd[1]);
    // Wait for first child.
    waitpid(data.pid_cmd1, NULL, 0);
    // Wait for second child.
    waitpid(data.pid_cmd2, NULL, 0);
    return (0);
}