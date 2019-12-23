/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:54:47 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 17:16:03 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_lefttrim(char const *s1, char const *set)
{
	int i;
	int j;

	j = 0;
	while (*s1)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (set[i] == *s1)
				break ;
			i++;
		}
		if (i < (int)ft_strlen(set))
			j++;
		else
			break ;
		s1++;
	}
	return (j);
}

static int	ft_rightrim(char const *s1, char const *set)
{
	int i;
	int j;
	int cont;

	j = 0;
	i = ft_strlen(s1) - 1;
	cont = ft_strlen(s1);
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
				break ;
			j++;
		}
		if (j < (int)ft_strlen(set))
			cont--;
		else
			break ;
		i--;
	}
	return (cont);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		size;

	if (!s1)
		return (0);
	if (ft_rightrim(s1, set) == 0)
		return (ft_strdup(""));
	size = ft_rightrim(s1, set) - ft_lefttrim(s1, set);
	ptr = ft_substr(s1, ft_lefttrim(s1, set), size);
	return (ptr);
}
