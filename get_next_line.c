#include <stdio.h>
#include "get_next_line.h"

static char *get_line(char *buffer)
{
	char *line;
	char *temp;
	size_t i;
	size_t buf_len;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
	{
		line = ft_substr(buffer, 0, i+1);
		temp = ft_strdup("");
		buf_len = 0;
		while (buffer[buf_len])
			buf_len++;
		temp = ft_strdup(buffer + (i+1));
		free(buffer);
		buffer = NULL;
		if (*temp)
		{
			printf("error");
			buffer = ft_strdup(temp);
		}
		free (temp);
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
		printf("\nbuffer no line: %s\n", buffer);

		return(line);
	}
	printf("\nbuffer no line: %s\n", buffer);
	return (line);
}

static char *get_read_file(int fd)
{
	// char *line;
	static char *buffer;
	char *temp_buffer;
	char *temp;
	size_t buf_len;
	ssize_t i;

	temp_buffer = ft_strdup("");
	// printf("temp1: %s", temp_buffer);
	i = read(fd, temp_buffer, BUFFER_SIZE);
	// printf("temp2: %s", temp_buffer);
	printf("buffer: %s", buffer);
	while (i > 0)
	{
		printf("aqui %lu", i);
		temp_buffer[i] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		temp = ft_strdup(buffer);
		free(buffer);
		buffer = ft_strjoin(temp, temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break;
		i = read(fd, temp_buffer, BUFFER_SIZE);
	}
	free(temp_buffer);
	buf_len = 0;
	while(buffer[buf_len])
		buf_len++;
	if (i == 0 && buffer == 0)
		return (NULL);
	return (get_line(buffer));
}

char *get_next_line(int fd)
{
	char *buffer;
	// char *line;
	ssize_t res;

	buffer = NULL;
	res = read(fd, buffer, 0);
	if (fd < 0 || res == -1 || BUFFER_SIZE < 1)
		return (NULL);
	// line = ft_strdup("");
	// line = get_read_file(fd, buffer, line);
	// if (line >= 0)
	// {
	// 	free(line);
	// 	line = NULL;
	// 	return (line);
	// }
	return (get_read_file(fd));
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (void)
{

	int fd = open("./teste3.txt", O_RDONLY);
	int i;
	char *a;
	// char *test;
	// test = get_next_line(fd);
	// if (fd == -1)
	// 	printf("error fd\n");
	// else
	// 	printf("sucesso fd: %d\n", fd);
	// printf("bytes: %d\n", BUFFER_SIZE);
	i = 1;

	while (i < 6)
	{
		a = get_next_line(fd);

		printf("\ntest%d: %s", i, a);
		if (a[0] == '\n')
			printf("oi");
		// get_next_line(fd);
		i++;
	}
	// printf("test1: %s\n", get_next_line(fd));
	close(fd);
}
// // // gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c