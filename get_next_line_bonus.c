/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguneyse <aguneyse@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:08:24 by aguneyse          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:25 by aguneyse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len <= ft_strlen(s) - start)
		sub = malloc(sizeof(char) * (len + 1));
	else
		sub = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!sub)
		return (0);
	while (*(s + start) && (i < len))
		*(sub + i++) = *(s + start++);
	*(sub + i) = '\0';
	return (sub);
}

int	get_next_buffer(int fd, char *str)
{
	int	a;

	a = read(fd, str, BUFFER_SIZE);
	if (a <= 0)
	{
		*str = 0;
		return (a);
	}
	*(str + a) = 0;
	return (a);
}

char	*new_str(int fd, char *str)
{
	char	*buffer;
	char	*tmp;
	int		checker;

	checker = 1;
	while (ft_strchr(str, '\n') == 0 && checker > 0)
	{
		tmp = str;
		buffer = malloc(BUFFER_SIZE + 1);
		*buffer = 0;
		checker = get_next_buffer(fd, buffer);
		str = ft_strjoin(str, buffer);
		free(buffer);
		free(tmp);
	}
	if (checker < 0 || (checker == 0 && ft_strlen(str) == 0))
	{
		free(str);
		return (0);
	}
	return (str);
}

char	*ft_seperate_newline(char **str)
{
	char	*line;
	char	*tmp;

	line = ft_substr(*str, 0, ft_strchr(*str, '\n') - *str + 1);
	tmp = *str;
	*str = ft_strdup(ft_strchr(*str, '\n') + 1);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*tmp;

	if (fd < 0 || fd > 256)
		return (0);
	if (!str[fd])
	{
		str[fd] = malloc(BUFFER_SIZE + 1);
		*str[fd] = 0;
	}
	if (!str[fd])
		return (0);
	str[fd] = new_str(fd, str[fd]);
	if (!str[fd])
		return (0);
	if (ft_strchr(str[fd], '\n'))
		return (ft_seperate_newline(&str[fd]));
	if (ft_strlen(str[fd]))
	{
		tmp = str[fd];
		str[fd] = 0;
		return (tmp);
	}
	return (0);
}
