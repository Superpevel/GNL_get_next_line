#include "get_next_line.h"
char	*check(char *remain, char **line)
{
	int		i;
	char	*tmp;

	tmp = 0;
	i = 0;
	if (!remain)
	{
		*line = 0;
		return (0);
	}
	while (remain[i])
	{
		if(remain[i] == '\n')
			break;
		i++;
	}
	if (remain[i])
		tmp = ft_substr(remain, i + 1, (ft_strlen(remain) - i));
	*line = ft_substr(remain, 0, i);
	free(remain);
	return (tmp);
}
int	ft_oper(int was_read, char *buf)
{
	free(buf);
	if (was_read == -1)
		return (-1);
	if (was_read == 0)
		return (0);
	return (1);
}
int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			was_read;
	static char	*remain;

	if (read(fd, 0, 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	was_read =1;
	while (!ft_strchr(remain) && was_read >0)
	{
		was_read = read(fd, buf, BUFFER_SIZE);
		buf[was_read] = '\0';
		remain= ft_strjoin(remain, buf);
	}
	remain = check(remain, line);
	return(ft_oper(was_read,buf));
}
// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("text.txt",O_RDONLY);
// 	while(get_next_line(fd,&line))
// 	{
// 		printf("%s\n",line);
// 	}

// }
