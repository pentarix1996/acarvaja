/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:50:09 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 02:37:46 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	str = 0;
	if (size <= 0)
		return (str);
	str = malloc(sizeof(*str) * (size + ft_strlen(sep)));
	if (!str)
		return (str);
	i = -1;
	k = 0;
	while (++i < (unsigned int)size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			str[k++] = strs[i][j];
		j = -1;
		if (i < (unsigned int)size - 1)
			while (sep[++j] != '\0')
				str[k++] = sep[j];
	}
	str[k] = '\0';
	return (str);
}
