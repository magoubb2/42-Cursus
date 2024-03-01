/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:59:54 by margueriteb       #+#    #+#             */
/*   Updated: 2024/03/01 18:18:54 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Function to clean up. */
// The clean_up function takes a string str as input  and  removes  the  first 
// line from it, returning the remaining content as a new string. It  iterates 
// through str to find the end of the first line or the  end  of  the  string, 
// allocates memory for the remaining content, copies  it  into  a  new string 
// rest, and ensures null termination. If str only consists of the first line, 
// it frees the  memory  and  returns  NULL.  Finally,  it  frees  the  memory 
// allocated for the original string  and  returns  the  pointer  to  the  new 
// string  containing  the   remaining   content   after   the   first   line.
static char *clean_up(char *str);

/* function to extract each line. */
// This function iterates through the input string str to find the end of  the 
// current line or the end of the string, allocating memory to store the line. 
// It then copies characters from str into the line buffer until it encounters
// a newline character or the end of the string. If memory  allocation  fails, 
// it returns NULL.  After  copying,  it  terminates  the  line  with  a  null 
// character ('\0') and  returns  the line. If the first character of the line 
// is  a  null  character, indicating  an  empty  line,   it   returns   NULL.
static char *extract_from_fd(char *str);

/* function that read. */
// reads data from a file descriptor (fd)  and  appends  it to a given  string 
// (str) until it encounters a newline character in str or reaches the end  of 
// the file. It employs a buffer (tmp_buff) to read data in  chunks  from  the 
// file descriptor, handling cases where the descriptor is empty or encounters
//  an error during reading. After reading each  chunk,  it  concatenates  the 
// buffer's contents to str  using  a  custom  string  concatenation  function 
// (ft_strjoin), updating  str  accordingly. If str  is  initially  empty,  it 
// duplicates the buffer  into  str  using ft_strdup. Memory allocated for the 
// previous contents of str is freed after each iteration. Finally, it returns 
// the updated string str containing the data  read from the  file descriptor. 
static char *read_from_fd(int fd, char *str);

static char *clean_up(char *str)
{
    int     i;
    int     j;
    char    *rest;

    i = 0;
    while (str[i])
    {
        if (str[i++] == '\n')
            break;
    }
    if (str[i])
        rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    else
    {
        free (str);
        return (NULL);
    }
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
    if (!str[i])
        line = (char *)malloc(sizeof(char) * (i + 1));
    else
        line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
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
    }
    line[i] = '\0';
    if (line[0] == '\0')
    {
        free(line);
        return (NULL);
    }
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
//     // printf("%s", get_next_line(fd));
//     // printf("%s\n", get_next_line(fd));
//     // printf("%s\n", get_next_line(fd));
//     // printf("%s\n", get_next_line(fd));
// } 