/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:59:54 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/22 13:10:36 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Function to clean up. */

// 1). clean up buffer after each line is stash.

/* function to extract each line. */

// 1). Extract line from the buffer.

/* function that read. */

static char *read_from_fd(int fd, char *str)
{
    // Initialise a buffer to store the character read from the fd.
    // Initialise counter to keep track of the current pos in the buffer.
    char    *new_str;
    char    tmp_buff[BUFFER_SIZE + 1];
    int     byte;

    byte = 1;
    new_str = NULL;
    printf("%s\n", str);
    // Loop until you find a newline and byte is not 0.
    while (!ft_strchr(str, '\n') && byte != 0)
    {
        // Assign the number of byte to read in fd to get the size of tmp.
        byte = read(fd, tmp_buff, BUFFER_SIZE);
        // NULL terminate the buffer.
        tmp_buff[byte] = '\0';
        // Join buffer to str.
        new_str = ft_strjoin(str, tmp_buff);
        // Assign str to new_str.
        str = new_str;
    }
    // Return the str.
    return (str);
}

/* The get_next_line function. */
char *get_next_line(int fd)
{
    static char *buffer;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    // if buffer empty or NULL, allocate memory for buffer.
    if (!buffer)
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    /* Function that read. */
    buffer = read_from_fd(fd, buffer);
    printf("%s\n", buffer);
    /* Function to extract each line. */
    /* Function to clean up. */
    return (line);
}

// int main(void)
// {
//     int fd = open("fd_test", O_RDONLY);
//     printf("%s\n", get_next_line(fd));
// }

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    // int fd = (int)atoi(*argv);
    int fd = open("fd_test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    // ft_putstr_fd("hello", open("test_fd", O_WRONLY));
}