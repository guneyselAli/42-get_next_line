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
	sub = malloc(sizeof(char) * (len + 1));
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
	if (a == 0)
	{
		if (*str != 0)
			return (2);
		free(str);
		return(0);
	}
	if (a < 0)
	{
		free (str);
		return (0);
	}
	*(str + a) = 0;
	return (3);
}

char *get_next_line(int fd)
{
	static char	*str;
	char 		*tmp;
	char		*line;
	int			checker;


	if (!str)
	{
		str = malloc(BUFFER_SIZE + 1);
		*str = 0;
	}
	if (!str)
		return (0);
	if (!ft_strchr(str,'\n'))
		checker = get_next_buffer(fd,str);
	if (checker == 0)
		return (0);
	while (1)
	{
		if (ft_strchr(str, '\n'))
		{	
			tmp = ft_strchr(str, '\n');
			line = ft_substr(str, 0, tmp - str + 1);
			str = ft_strdup(tmp + 1);
			return (line);
		}
		tmp = malloc(BUFFER_SIZE + 1);
		checker = get_next_buffer(fd,tmp);
		str = ft_strjoin(str,tmp);
		if (checker == 2)
			return (str);
	}
}

int main(void)
{
	int fd = open("alternate_line_nl_with_nl", O_RDWR);
	char *a = get_next_line(fd);
	while (a)
	{
		printf("%s",a);
		a = get_next_line(fd);
	}
	printf("%s", a);
}

