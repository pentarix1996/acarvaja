/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:56:39 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/08 10:52:29 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					result;
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	result = 0;
	ptrs1 = s1;
	ptrs2 = s2;
	while (n-- > 0)
	{
		if (*ptrs1 != *ptrs2)
		{
			result = (unsigned char)*ptrs1 - (unsigned char)*ptrs2;
			break ;
		}
		ptrs1++;
		ptrs2++;
	}
	return (result);
}
