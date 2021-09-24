#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	char *new_str;
	size_t i;

	i = 0;
	new_str = malloc(nmemb * size);
	if (!new_str)
		return (0);
	while (i < (nmemb * size))
	{
		new_str[i] = '\0';
		i++;
	}
	return ((void *)new_str);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *j;
	unsigned char *z;
	size_t i;

	if (!dest && !src)
		return (0);
	j = dest;
	z = (void *)src;
	i = 0;
	while (i < n)
	{
		j[i] = z[i];
		i++;
	}
	return (dest);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len < dstsize)
	{
		while (i < (dstsize - 1 - dst_len) && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *new_str;
	size_t s1_len;
	size_t s2_len;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, s1, s1_len);
	ft_strlcat(new_str, s2, (s1_len + s2_len + 1));
	return (new_str);
}