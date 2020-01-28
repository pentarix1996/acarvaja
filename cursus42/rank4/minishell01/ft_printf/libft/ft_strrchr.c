/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:21:43 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/12 12:13:12 by acarvaja         ###   ########.fr       */
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

char			*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	s += ft_strlen(s);
	while (i >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (0);
}
