/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:44:36 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:47 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	ptrdst = dst;
	ptrsrc = src;
	if (!dst && !src)
		return (NULL);
	if (ptrsrc + len > ptrdst && src < dst)
	{
		ptrsrc += len - 1;
		ptrdst += len - 1;
		while (len-- > 0)
			*ptrdst-- = *ptrsrc--;
	}
	else
	{
		while (len-- > 0)
			*ptrdst++ = *ptrsrc++;
	}
	return (dst);
}
