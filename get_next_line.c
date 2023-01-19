/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguneyse <aguneyse@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:26:06 by aguneyse          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:07 by aguneyse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

int get_next_buffer(int fd, char *str)
{
	int a;

	a = read(fd, str, BUFFER_SIZE);
	if (a <= 0)
	{
		*str = 0;
		return(a);
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
	if (checker < 0)
	{
		free(str);
		return (0);
	}		
	if (checker == 0 && ft_strlen(str) == 0)
	{
		free(str);
		return (0);
	}
	return (str);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*line;

	if (!str)
	{
		str = malloc(BUFFER_SIZE + 1);
		*str = 0;
	}
	if (!str)
		return (0);
	str = new_str(fd,str);
	if (!str)
		return (0);
	if (ft_strchr(str, '\n'))
	{
		line = ft_substr(str, 0, ft_strchr(str, '\n') - str + 1);
		tmp = str;
		str = ft_strdup(ft_strchr(str, '\n') + 1);
		free(tmp);
		return (line);
	}
	if (ft_strlen(str))
	{
		tmp = str;
		str = 0;
		return (tmp);
	}
	return (0);
}

/*
int main(void)
{
	int fd = open("alternate_line_nl_with_nl", O_RDWR);
	char *a = get_next_line(fd);
	while (a)
	{
		printf("%s",a);
		a = get_next_line(fd);
	}
	printf("%s",a);
}*/