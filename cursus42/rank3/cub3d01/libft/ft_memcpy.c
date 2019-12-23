/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:46:58 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/08 11:41:13 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrdst;
	const char		*ptrsrc;

	if (!dst && !src)
		return (NULL);
	ptrsrc = src;
	ptrdst = dst;
	while (n-- > 0)
		*ptrdst++ = *ptrsrc++;
	return (dst);
}
