/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:46:24 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/13 13:55:29 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static char	**ft_createtab(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return ((char **)malloc(sizeof(char *) * (count + 1)));
}

static char	*ft_returnstr(char *tmp, char c)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
			tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

static void	ft_putnull(int i[3])
{
	i[0] = 0;
	i[1] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	char	*tmp;
	int		i[3];

	if (s == 0)
		return (0);
	tmp = ft_strdup(s);
	i[2] = ft_strlen(s);
	if (!(result = ft_createtab(s, c)))
		return (0);
	tmp = ft_returnstr(tmp, c);
	ft_putnull(i);
	while (i[0] < i[2])
	{
		if (!tmp[i[0]])
			i[0]++;
		else
		{
			result[i[1]++] = ft_strdup(&tmp[i[0]]);
			i[0] += ft_strlen(&tmp[i[0]]);
		}
	}
	result[i[1]] = 0;
	return (result);
}
