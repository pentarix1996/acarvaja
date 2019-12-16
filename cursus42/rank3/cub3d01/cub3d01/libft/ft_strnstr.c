/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:09:33 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/13 16:04:09 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		lcompare(const char *dest, const char *src, size_t len)
{
	while (*dest && *src && len--)
	{
		if (*dest != *src && len >= 0)
			return (0);
		dest++;
		src++;
	}
	return (*src == '\0');
}

char			*ft_strnstr(const char *dst, const char *need, size_t len)
{
	if (*need == '\0')
		return ((char *)dst);
	while (*dst != '\0' && len > 0)
	{
		if ((*dst == *need) && lcompare(dst, need, len))
			return ((char *)dst);
		dst++;
		len--;
	}
	return (0);
}
