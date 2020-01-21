/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:38:55 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/02 10:32:40 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
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

char *ft_strdup(char *s)
{
	char *ptr;

	if (!(ptr = malloc(sizeof(*ptr) * (ft_strlen(s) + 1))))
		return (0);
	ft_strcpy(ptr, s);
	return (ptr);
}

char *ft_strchr(char *str, char c)
{
	int i;
	
	i = ft_strlen(str);
	while (i-- >= 0)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char *ft_strcat(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

int	ft_get_line(char **memory,  char **line, int ret)
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
	char buff[129];
	static char *memory;

	if (!line)
		return (-1);
	while ((ret = read(0, buff, 128)) > 0)
	{
		buff[ret] = '\0';
		if (!memory)
			memory = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(memory, buff);
			free (memory);
			memory = tmp;
		}
		if (ft_strchr(memory, '\n'))
			break ;
	}
	return (ft_get_line(&memory, line, ret));
}
