#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char *new_str;
	size_t i;
	size_t j;

	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while(s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i+j] = s2[j];
		j++;
	}
	new_str[i+j] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char *dup;
	size_t i;

	dup = malloc(ft_strlen(s) + 1);
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

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char *new_str;
	size_t i;
	size_t st;

	if (!s)
		return (0);
	st = (size_t)start;

	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
	{
		free(new_str);
		return (0);
	}
	i = 0;
	while (i < len && s[st + i])
	{
		new_str[i] = s[st + i];
		i++;
	}
	new_str[i] = '\0';
	free(s);
	return (new_str);
}
