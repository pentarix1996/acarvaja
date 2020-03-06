/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:03 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/18 19:49:12 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int tam;

	tam = 0;
	while (*s++)
		tam++;
	return (tam);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc(sizeof(*copy) * (ft_strlen(s1) + 1));
	if (!copy)
		return (0);
	ft_strcpy(copy, s1);
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i-- >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
