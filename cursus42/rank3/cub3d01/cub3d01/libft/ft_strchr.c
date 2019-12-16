/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:15:23 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/13 10:14:48 by acarvaja         ###   ########.fr       */
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

char			*ft_strchr(const char *s, int c)
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
