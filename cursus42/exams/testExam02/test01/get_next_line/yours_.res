/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nest_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:07:05 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/02 10:46:52 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strdup(char *str)
{
	char *copy;

	copy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (0);
	ft_strcpy(copy, str);
	return (copy);
}

char *ft_strchr(char *str, int c)
{
	int i;

	i = ft_strlen(str);
	while (i-- >= 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}

char *ft_strcat(char *dst, char *src)
{
	int i;
	int j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;

	if (!(s1 && s2))
		return (0);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}

int ft_get_line(char **memory, char **line, int ret)
{
	char *aux1;
	char *aux2;

	if (ret < 0)
		return (-1);
	if (!*memory && !ret)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((aux1 = ft_strchr(*memory, '\n')))
	{
		*aux1 = 0;
		*line = ft_strdup(*memory);
		aux2 = ft_strdup(++aux1);
		free(*memory);
		*memory = aux2;
	}
	else
	{
		*line = *memory;
		*memory = 0;
		return (0);
	}
	return (1);
}

int get_next_line(char **line)
{
	int ret;
	char *tmp;
	static char *memory;
	char buff[129];

	if (line == 0)
		return (-1);
	while ((ret = read(0, buff, 128)) > 0)
	{
		buff[ret] = '\0';
		if (!memory)
			memory = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(memory, buff);
			free(memory);
			memory = tmp;
		}
		if (ft_strchr(memory, '\n'))
			break ;
	}
	return (ft_get_line(&memory, line, ret));
}
