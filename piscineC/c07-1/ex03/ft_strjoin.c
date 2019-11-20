/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:50:09 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 09:41:25 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while ((dest[i] = src[j]) != '\0')
	{
		i++;
		j++;
	}
	return (dest);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = size;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	while (j > 0)
		i += ft_strlen(strs[--j]);
	if ((p = (char *)malloc(i * sizeof(*p))) != NULL && size > 0)
	{
		*p = '\0';
		while (j < size - 1)
		{
			p = ft_strcat(p, strs[j++]);
			p = ft_strcat(p, sep);
		}
		p = ft_strcat(p, strs[j]);
	}
	return (p);
}
