/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:02:01 by margueriteb       #+#    #+#             */
/*   Updated: 2024/03/23 17:55:21 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* The command we have to execute : < file1 cmd1 | cmd2 > file2 */

/* This project is a programm so it has a main in it. */

/* Check existence of infile and outfile (with the access function) */

/* If the file does not exist and we use the SIR ('<') we create it. */

/* Create the necessary pipe. */

/* Create the child process for each command. */

/* Wait for all the process to end before writing to the outfile. */


int main(int argc, char **argv, char **env) 
{
    if (argc != 5)
        // return error

    // 1). Check for errors.
    
    // 2). Initialise infile.
    
    // 3). Initialise outfile.

    // 4). Create necessary pipe.

    // 5). Get the path.

    // 6).Get the command path.

    // 7). First child process.
        // Execute the first command.
    
    // 8).Second child process.
        // Execute second command.
    
    // 9).
    // Close pipe.
    // Wait for first child.
    // Wait for second child.
}