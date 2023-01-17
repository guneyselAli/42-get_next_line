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

char *get_next_line(int fd)
{
    char    *str;
    size_t i;
    int a;

    i = 0;
    str = malloc(BUFFER_SIZE);
    while (i < BUFFER_SIZE) 
    {
        a = read(fd, str + i, 1);
        if (*(str + i) == '\n')
        {
            *(str + i + 1) = 0;
            break;
        }
        if (a == 0)
        {
            *(str + i) = 0;
            break;
        }
        if (a < 0)
        {
            free (str);
            return (NULL);
        }
        i++;
    }
    return (str);
}

/*
int main(void)
{
    int fd = open("get_next_line.c", O_RDWR);

    while (1)
    {
        char *a = get_next_line(fd);

        printf("%s",a);

        if (!a)
        {
            free(a);
            break;
        }
    }
}*/