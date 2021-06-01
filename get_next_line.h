#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 35
#endif
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int     get_next_line(int fd, char **line);
int		ft_strchr(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
