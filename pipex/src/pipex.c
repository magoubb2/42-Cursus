/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:01 by margueriteb       #+#    #+#             */
/*   Updated: 2024/03/25 16:19:05 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


/* The command we have to execute : < file1 cmd1 | cmd2 > file2 */

/* This project is a programm so it has a main in it. */

/* Check existence of infile and outfile (with the access function) */

/* If the file does not exist and we use the SIR ('<') we create it. */

/* Create the necessary pipe. */

/* Create the child process for each command. */

/* Wait for all the process to end before writing to the outfile. */

// First command.
// static void first_child(t_data data, char **argv, char **env)
// {
        //dup2()
        //close()
        //execve()
// }

// Returns the value of env.
static char *path(char **env)
{
    int i;

    i = 0;
    // Loop until the end of the env array is reached.
    // Loop through the array of string untils finding the one starting
    // with "PATH".
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
    // if (data.pid_cmd1 == 0)
        // Execute the first command.
        // first_child(data, argv, env);
    // 8).Second child process.(fork)
        // Execute second command.
    
    // 9).
    // Close pipe.
    // Wait for first child.
    // Wait for second child.
}