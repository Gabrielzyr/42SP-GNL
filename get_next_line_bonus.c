/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:51:01 by gamonte-          #+#    #+#             */
/*   Updated: 2021/10/12 23:15:16 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_read_file(int fd, char **save, char *line, ssize_t i)
{
	char	temp_line[BUFFER_SIZE + 1];

	while (i > 0)
	{
		i = read(fd, temp_line, BUFFER_SIZE);
		temp_line[i] = '\0';
		line = ft_strjoin_free(line, temp_line);
		if (ft_strchr(line, '\n'))
		{
			*save = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr_free(line, 0, ft_strlen(line) - ft_strlen(*save));
			break ;
		}
	}
	if (i == 0 && line[i] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[256];
	char		*line;

	line = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, line, 0) < 0))
	{
		free(line);
		return (NULL);
	}
	free(line);
	if (!save[fd])
		save[fd] = ft_strdup("");
	line = ft_strdup(save[fd]);
	free(save[fd]);
	save[fd] = NULL;
	return (get_read_file(fd, &save[fd], line, 1));
}
