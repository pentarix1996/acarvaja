/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:27:46 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/11 21:14:53 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*ptrdst;
	const char	*ptrsrc;
	size_t		n;
	size_t		dlen;

	ptrdst = dst;
	n = dstsize;
	ptrsrc = src;
	while (n-- && *ptrdst)
		ptrdst++;
	dlen = ptrdst - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(ptrsrc));
	while (*ptrsrc)
	{
		if (n != 1)
		{
			*ptrdst++ = *ptrsrc;
			n--;
		}
		ptrsrc++;
	}
	*ptrdst = '\0';
	return (dlen + (ptrsrc - src));
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	c;

	if (!(dst && src))
		return (0);
	c = ft_strlen(src);
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (c);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!(s1 && s2))
		return (0);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(ptr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ptr);
}

static int	ft_get_line(char **memory, char **line, int rev)
{
	char	*aux1;
	char	*aux2;

	if (rev < 0)
		return (-1);
	if (!*memory && !rev)
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
		*memory = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*memory[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == 0 || !BUFFER_SIZE)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!memory[fd])
			memory[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(memory[fd], buff);
			free(memory[fd]);
			memory[fd] = tmp;
		}
		if (ft_strchr(memory[fd], '\n'))
			break ;
	}
	return (ft_get_line(&memory[fd], line, ret));
}
