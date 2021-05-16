#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
#include <fcntl.h>
// #define BUFFER_SIZE 35
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
int get_next_line(int fd, char **line);
void	ft_strclr(char *s);
char	*ft_strrchr(const char *s, int c);
#endif
