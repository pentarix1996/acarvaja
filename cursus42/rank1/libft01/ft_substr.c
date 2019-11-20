/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:29:31 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 17:20:26 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return ((char *)ft_calloc(start * sizeof(char), len));
	s += start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
