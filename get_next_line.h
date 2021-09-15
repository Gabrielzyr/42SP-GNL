#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t ft_strlen(const char *s);
void *ft_calloc(size_t nmemb, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
char *ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);

#endif