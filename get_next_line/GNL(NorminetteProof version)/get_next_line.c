/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:59:54 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/29 12:06:53 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Function to clean up. */
// Get the size of the current string.
// Allocate the size for the rest of what is in (str) by substracting the
// size of the current line to the full len of (str).
// If there are no more character in (str) free str.
// Move to the next char in (str) to not copy it in the (rest) string.
// Copy (str) into (rest).
// Make sure (rest) is NULL terminated.
// Free what's in the old buffer.
// Return (rest).
static char *clean_up(char *str);

/* function to extract each line. */
// Loop in the (str) array until you find '\n' or '\0' to get the size of line.
// Malloc the size of line.
// If malloc fails.
// Copy (str) into (line) until you find '\n' or '\0'.
// If a '\n' is found replace it by a '\0' to indicate that the current line is done.
// Else if str[i] = '\0' add the '\0' to say the line is done.
// For if only new lines.
static char *extract_from_fd(char *str);

/* function that read. */
// Loop until you find a newline and byte is not 0.
// Assign the number of byte to read in fd to get the size of tmp.
// For when fd is empty.
// If byte == -1.
// If byte == -1 and there is something in str.
// NULL terminate the buffer.
// Join buffer to str.
// If it's str is empty duplicate tmp_buff into str.
// If str is not empty.
// Assign str to new_str.
// Return the str.
static char *read_from_fd(int fd, char *str);

static char *clean_up(char *str)
{
    int     i;
    int     j;
    char    *rest;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i])
        rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    else
    {
        free (str);
        return (NULL);
    }
    i++;
    j = 0;
    while (str[i])
    {
        rest[j] = str[i];
        i++;
        j++;
    }
    rest[j] = '\0';
    free(str);
    return (rest);
}

static char *extract_from_fd(char *str)
{
    char    *line;
    int     i;
    
    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
    {
        return (NULL);
        free(line);
    }
    i = 0;
    while (str[i] != '\n' && str[i])
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = str[i];
        i++;
        line[i] = '\0';
    }
    else
        line[i] = '\0';
    if (line[0] == '\0')
        return (NULL);
    return (line);
}

static char *read_from_fd(int fd, char *str)
{
    char    *new_str;
    char    tmp_buff[BUFFER_SIZE + 1];
    int     byte;

    byte = 1;
    new_str = NULL;
    while (!ft_strchr(str, '\n') && byte != 0)
    {
        byte = read(fd, tmp_buff, BUFFER_SIZE);
        if (byte == 0  && !str)
            return (NULL);
        if (byte == -1)
        {
            if (str)
                free (str);
            return (NULL);
        }
        tmp_buff[byte] = '\0';
        new_str = ft_strjoin(str, tmp_buff);
        if (!str)
           str = ft_strdup(tmp_buff);
        else
        {
            if (str)
                free (str);
            str = new_str;
        }
    }
    return (str);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buffer = read_from_fd(fd, buffer);
    if (!buffer)
        return (NULL);
    line = extract_from_fd(buffer);
    buffer = clean_up(buffer);
    return (line);
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     int fd;
//     fd = open(argv[1], O_RDONLY);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     // printf("%s\n", get_next_line(fd));
//     // printf("%s\n", get_next_line(fd));
// }