/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:10:15 by margueriteb       #+#    #+#             */
/*   Updated: 2024/02/20 18:16:04 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1). Find the number of words in (s).
// 2). With the number of words we can allocate the number of arrays we are
//     gonna need.
// 3). Then we are going to copy the current word in (new_str) using substr.
char	**ft_split(const char *s, char c);

static int	count_wd(char *str, char c)
{
	int	i;
	int	word_nb;

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

static int	w_len(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**d_tab;
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	d_tab = ft_calloc(sizeof(char *), (count_wd((char *)s, c) + 1));
	if (!d_tab)
		return (NULL);
	while ((size_t)i < ft_strlen(s))
	{
		if ((((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))))
		{
			d_tab[index] = ft_substr(s, i, w_len((char *)s, c, i + 1) + 1);
			if (!d_tab[index])
				return (free_tab (d_tab));
			index++;
		}
		i++;
	}
	d_tab[index] = NULL;
	return (d_tab);
}

// int	main(void)
// {
// 	char	**split = ft_split("hello!zword", 'z');
// 	int i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }