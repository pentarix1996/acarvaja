/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:47:23 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/13 09:44:05 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	int tam;

	tam = 0;
	while (*s++)
		tam++;
	return (tam);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
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
