#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char c;
	char buf[10+1];
	int was_read;
	char *p_n;
	int flag;
	static char *remain;
	char *tmp;

	flag =1;
	*line = "\0";
	if(remain)
	{
		printf("%s",remain);

	}
	else
	{
		remain = "\0";
	}

	while(flag && (was_read =  read(fd,buf,10)))
	{
		buf[was_read] = '\0';
		if((p_n = ft_strchr(buf,'\n')))
		{
			*p_n = '\0';
			p_n++;
			remain = strdup(p_n);
			flag = 0;
		}
		tmp = *line;
		*line = ft_strjoin(*line,buf);
	}
	return(0);
}

int main()
{
	char *line;
	int fd;

	fd = open("text.txt",O_RDONLY);
	get_next_line(fd,&line);
	get_next_line(fd,&line);
}
