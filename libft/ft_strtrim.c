
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int str_len;
	char *new_str;

	i = 0;
	j = 0;
	str_len = ft_strlen(s1) - (ft_strlen(set) * 2);
	new_str = (char *)malloc(sizeof(char *) * (str_len));
	if (!new_str)
		return (NULL);
	while (s1[i] == set[i])
	{
		i++;
		j++;
	}
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("abc hello  world abc  lol", "abc "));
// }