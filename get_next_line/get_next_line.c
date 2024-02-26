/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:59:54 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/26 13:57:40 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Function to clean up. */
static char *clean_up(char *str)
{
    // Counter for str.
    // Counter for rest.
    // string to store the rest.
    int     i;
    int     j;
    char    *rest;

    i = 0;
    // Get the size of the current string.
    while (str[i] && str[i] != '\n')
        i++;
    // Allocate the size for the rest of what is in (str) by substracting the
    // size of the current line to the full len of (str).
    if (str[i])
        rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    else
    {
        return (NULL);
        free (str);
    }
    // Move to the next char in (str) to not copy it in the (rest) string.
    i++;
    // If malloc fails.
    if (!rest)
    {
        return (NULL);
        free (rest);
    }
    j = 0;
    // Copy (str) into (rest).
    while (str[i])
    {
        rest[j] = str[i];
        i++;
        j++;
    }
    // Make sure (rest) is NULL terminated.
    rest[j] = '\0';
    // Free what's in the old buffer.
    free(str);
    // Return (rest).
    return (rest);
}

/* function to extract each line. */
static char *extract_from_fd(char *str)
{
    // Initialise variable that will store the currenct line.
    // Initialise a counter.
    char    *line;
    int     i;
    
    i = 0;
    // Loop in the (str) array until you find '\n' or '\0' to get the size of line.
    while (str[i] != '\n' && str[i])
        i++;
    // Malloc the size of line.
    line = (char *)malloc(sizeof(char) * (i + 2));
    // If malloc fails.
    if (!line)
    {
        return (NULL);
        free(line);
    }
    i = 0;
    // Copy (str) into (line) until you find '\n' or '\0'.
    while (str[i] != '\n' && str[i])
    {
        line[i] = str[i];
        i++;
    }
    // If a '\n' is found replace it by a '\0' to indicate that the current line is done.
    if (str[i] == '\n')
    {
        line[i] = str[i];
        line[i] = '\0';
        i++;
    }
    // Else if str[i] = '\0' add the '\0' to say the line is done.
    else
        line[i] = '\0';
    return (line);
}

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
        if (str)
            free(str);
    }
    // Return the str.
    return (str);
}

/* The get_next_line function. */
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    // If buffer empty or NULL, allocate memory for buffer.
    if (!buffer)
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        // If malloc fails.
        if (!buffer)
        {
            return (NULL);
            free(buffer);
        }
    }
    /* Function that read. */
    buffer = read_from_fd(fd, buffer);
    /* Function to extract each line. */
    line = extract_from_fd(buffer);
    /* Function to clean up for next line */
    buffer = clean_up(buffer);
    return (line);
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     int fd;
//     fd = open(argv[1], O_RDONLY);
//     // printf("%i\n", fd);
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     // printf("%i\n", fd);
// }