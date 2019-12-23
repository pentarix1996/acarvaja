/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:15:40 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 15:02:08 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	ptrdst = dst;
	ptrsrc = src;
	while (n-- > 0)
	{
		*ptrdst++ = *ptrsrc;
		if (*ptrsrc++ == (unsigned char)c)
			return (ptrdst);
	}
	return (NULL);
}
