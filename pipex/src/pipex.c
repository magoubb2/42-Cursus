/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:01 by margueriteb       #+#    #+#             */
/*   Updated: 2024/03/23 18:20:52 by margueriteb      ###   ########.fr       */
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


int main(int argc, char **argv, char **env) 
{

    t_data data;
    
    if (argc != 5)
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
    data.path = 
    // 6).Get the command path.
    data.path_to_cmd = 
    // 7). First child process.(fork)
        // Execute the first command.
    
    // 8).Second child process.(fork)
        // Execute second command.
    
    // 9).
    // Close pipe.
    // Wait for first child.
    // Wait for second child.
}