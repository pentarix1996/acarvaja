/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:30:34 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/14 15:08:31 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	pos;

	c = (unsigned char)c;
	pos = 0;
	if (!s || !c)
		return (NULL);
	while (s[pos])
	{
		if (s[pos] == c)
			return ((char *)&s[pos]);
		pos++;
	}
	return (NULL);
}
