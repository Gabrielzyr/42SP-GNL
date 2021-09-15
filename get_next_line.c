#include <stdio.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	// size_t		res;
	static char	file[BUFFER_SIZE];
	int			i;

	if (!fd || fd == -1 || !BUFFER_SIZE)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE && file[i - 1] != '\n')
	{
		read(fd, file + i, 1);
		// printf("\nfile: %c\n",file[i]);
		// line[i] = (char)file[i];
		i++;
	}
	// printf("\nline: %s\n", file);

	// // res = read(fd, file, BUFFER_SIZE);

	// // printf("file2: %s\n", file);
	return (file);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int main (void)
// {

// 	int fd = open("./teste.txt", O_RDONLY);
// 	// char *test;
// 	// test = get_next_line(fd);
// 	// if (fd == -1)
// 	// 	printf("error fd\n");
// 	// else
// 	// 	printf("sucesso fd: %d\n", fd);
// 	// printf("bytes: %d\n", BUFFER_SIZE);
// 	printf("test1: %s\n", get_next_line(fd));
// 	printf("test2: %s\n", get_next_line(fd));
// 	printf("test3: %s\n", get_next_line(fd));
// 	printf("test4: %s\n", get_next_line(fd));
// 	close(fd);
// }
// // gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c