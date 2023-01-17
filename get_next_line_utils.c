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

/*char	*ft_strjoin(char const *s1, char const *s2)
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
}*/
