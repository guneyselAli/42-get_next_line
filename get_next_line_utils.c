/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguneyse <aguneyse@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:04:06 by aguneyse          #+#    #+#             */
/*   Updated: 2023/01/17 19:04:08 by aguneyse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*(str + len))
		len++;
	return(len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*a;

	len = ft_strlen(s1);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (0);
	ft_memcpy(a, s1, len + 1);
	return (a);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = dst;
	p_src = src;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*p_dst++ = *p_src++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (0);
	while (*s1)
		*(p + i++) = *(s1++);
	while (*s2)
		*(p + i++) = *(s2++);
	*(p + i) = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + len));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}