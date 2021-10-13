/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:51:33 by gamonte-          #+#    #+#             */
/*   Updated: 2021/10/12 23:04:01 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_substr_free(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
