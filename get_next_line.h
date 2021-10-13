#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strjoin_free(char *s1, char const *s2);
char *ft_substr_free(char *s, unsigned int start, size_t len);
char *get_next_line(int fd);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);

#endif
