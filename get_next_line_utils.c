#include "get_next_line.h"
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
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(a = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (s1)
		while (s1[j] != '\0')
			a[i++] = s1[j++];
	j = 0;
	free(s1);
	if (s2)
		while (s2[j] != '\0')
			a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

int		ft_strchr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	max_len(char const *s, unsigned int start)
{
	size_t	i;

	i = ft_strlen(s) - start ;
	return (i);
}

char	*ft_sub_fill(char const *s, unsigned int start, size_t len, char *sub)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	j = max_len(s, start);
	if (len < j)
	{
		sub = malloc(sizeof(char) * (len + 1));
		if (!(sub))
			return (NULL);
		return (ft_sub_fill(s, start, len, sub));
	}
	else
	{
		sub = malloc(sizeof(char) * (j + 1));
		if (!(sub))
			return (NULL);
		return (ft_sub_fill(s, start, j, sub));
	}
}