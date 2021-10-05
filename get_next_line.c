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

char *get_line(char *line, char *buffer)
{
	static char *buffer_save;
	char *temp;
	size_t i;
	size_t buf_len;

	i = 0;
	if (!buffer_save)
		buffer_save = ft_strdup("");
	buffer_save = ft_strjoin(buffer_save, buffer);
	if (ft_strlen(buffer_save) == 0 && ft_strlen(buffer) == 0)
	{
		free(buffer_save);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	while (buffer_save[i] != '\n' && buffer_save[i])
		i++;
	if (buffer_save[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
	{
		free(line);
		return (0);
	}
	line = ft_memcpy(line, buffer_save, i);
	buf_len = 0;
	while (buffer_save[buf_len])
		buf_len++;
	temp = ft_strdup("");
	ft_memcpy(temp, buffer_save+i, buf_len - i);
	free(buffer_save);
	buffer_save = ft_strdup(temp);
	free(temp);
	return (line);
}

char *get_read_file(int fd, char *buffer, char *line)
{
	char *temp_buffer;
	ssize_t i;

	if (!buffer)
		buffer = ft_strdup("");
	temp_buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	i = 1;
	while (i)
	{
		i = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break;
		else if (i <= 0)
			break;
	}
	free(temp_buffer);
	line = get_line(line, buffer);
	return (line);
}

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;
	ssize_t res;

	res = read(fd, buffer, 0);
	if (fd < 0 || res == -1 || !BUFFER_SIZE)
		return (NULL);
	line = ft_strdup("");
	line = get_read_file(fd, buffer, line);
	if (!line)
		return (0);
	// printf("buffer2: %s\n", buffer);
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int main (void)
// {

// 	int fd = open("./teste.txt", O_RDONLY);
// 	int i;
// 	// char *test;
// 	// test = get_next_line(fd);
// 	// if (fd == -1)
// 	// 	printf("error fd\n");
// 	// else
// 	// 	printf("sucesso fd: %d\n", fd);
// 	// printf("bytes: %d\n", BUFFER_SIZE);
// 	i = 1;

// 	while (i < 14)
// 	{
// 		printf("\ntest%d: %s\n", i, get_next_line(fd));
// 		// get_next_line(fd);
// 		i++;
// 	}
// 	// printf("test1: %s\n", get_next_line(fd));
// 	close(fd);
// }
// // // // gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c