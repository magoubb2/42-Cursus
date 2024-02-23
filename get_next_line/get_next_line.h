/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:59:56 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/23 13:02:59 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 

# define BUFFER_SIZE 1024

int     ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char    *get_next_line(int fd);

#endif