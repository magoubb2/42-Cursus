/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:10:15 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/17 12:06:59 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_wd(char *str, char c)
{
    int i;
    int word_nb;

    i = 0;
    word_nb = 0;
    while (str[i])
    {
        while (str[i] == c)
            i++;
        if (str[i] != '\0')
            word_nb++;
        while (str[i] && (str[i] != c))
            i++;
    }
    return (word_nb);
}

static int w_len(char *str, char c, int i)
{
    int len;

    len = 0;
    while (str[i] != c && str[i])
    {
        i++;
        len++;
    }
    return (len);
}

char **ft_split(const char *s, char c)
{
    char **d_tab;
    int i;
    int index;
    
    i = 0;
    index = 0;
    if(!s)
        return (NULL);
    d_tab = malloc(sizeof(char *) * (count_wd((char *)s, c) + 1));
    if (!d_tab)
        return (NULL);
    while (i < ft_strlen(s))
    {
        if ((((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))))
        {
            d_tab[index] = ft_substr(s, i, w_len((char *)s, c, i + 1) + 1);
            index++;
        }
        i++;
    }
    d_tab[index] = NULL;
    return (d_tab);
}

// int main(void)
// {
//     printf("%s\n", (char *)ft_split("hello world world", ' '));
//     printf("count word: %i\n", count_wd("hello world", ' '));
// }

int	main(void)
{
	char	**split = ft_split("lol lmao", ' ');
	int i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}