#include "get_next_line.h"
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (c == str[i])
		return (((char *)str + i));
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	k = -1;
	while (++k < i)
		new[k] = s1[k];
	j = k + j;
	i = 0;
	while (k < j)
	{
		new[k] = s2[i];
		k++;
		i++;
	}
	new[k] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = ft_strlen(s1);
	j = 0;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!(s2))
		return (NULL);
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
