#include <stdio.h>
#include "get_next_line.h"

char *ft_strdup(const char *s)
{
	char *dup;
	size_t i;

	dup = malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char *get_next_line(int fd)
{
	static char *file;
	char *line;
	char *str;
	char *temp;
	int i;
	ssize_t res;

	res = read(fd, file, 0);
	if (fd < 0 || res == -1 || !BUFFER_SIZE)
		return (NULL);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = read(fd, line, BUFFER_SIZE);
	if (i == 0 && !file)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (!file)
		file = ft_strdup("");
	str = ft_strdup("");
	temp = ft_strdup("");
	while (i)
	{
		line[i] = '\0';
		temp = ft_strdup(file);
		free(file);
		file = ft_strjoin(temp, line);
		// printf("file: %s", line);
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp, line);
		// printf("i: %d", i);
		if (ft_strchr(line, '\n')) break;
		i = read(fd, line, BUFFER_SIZE);	
	}
	if (i == 0)
	{
		free(file);
		file = NULL;
	}
	free(line);
	line = NULL;
	return (str);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (void)
{

	int fd = open("./teste2.txt", O_RDONLY);
	int i;
	// char *test;
	// test = get_next_line(fd);
	// if (fd == -1)
	// 	printf("error fd\n");
	// else
	// 	printf("sucesso fd: %d\n", fd);
	// printf("bytes: %d\n", BUFFER_SIZE);
	i = 1;

	while (i < 8)
	{
		printf("test%d: %s\n", i, get_next_line(fd));
		i++;
	}
	close(fd);
}
// // // gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c