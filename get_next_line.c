#include "get_next_line.h"
char *check(char *remain,char **line)
{
	char *p_n;

	p_n = NULL;
	if(remain)
	{
		if((p_n = ft_strchr(remain,'\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remain);
			ft_strcpy(remain,++p_n);
		}
		else
		{
			*line = ft_strdup(remain);
			ft_strclr(remain);
		}
	}
	else
		*line = ft_strnew(1);
	return(p_n);
}
int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE+1];
	int was_read;
	char *p_n;

	static char *remain;
	char *tmp;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	p_n = check(remain,line);
	while(!p_n && (was_read =  read(fd,buf,BUFFER_SIZE)))
	{
		buf[was_read] = '\0';
		if((p_n = ft_strchr(buf,'\n')))
		{
			*p_n = '\0';
			p_n++;
			remain = strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line,buf);
		free(tmp);
	}
	if (was_read == 0 )
		return(0);
	return(1);
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
