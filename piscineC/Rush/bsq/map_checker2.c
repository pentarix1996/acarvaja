/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:27:25 by atorres-          #+#    #+#             */
/*   Updated: 2019/09/24 15:24:20 by atorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_chars(char *mapname)
{
	int		i;
	int		j;
	int		finder;
	char	key[4];

	i = 0;
	j = 0;
	finder = 0;
	i = ft_first_line(mapname);
	key[3] = '\0';
	key[2] = mapname[--i];
	key[1] = mapname[--i];
	key[0] = mapname[--i];
	if (key[0] == key[1] || key[0] == key[3] || key[2] == key[3])
		return (1);
	finder = ft_finder((mapname + i), key);
	return (finder);
}

int		ft_finder(char *str, char *key)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	while (str[i] != '\0')
	{
		if (str[i] != key[0] && str[i] != key[1]
				&& str[i] != key[2] && str[i] != '\n')
		{
			find = 1;
			break ;
		}
		i++;
	}
	return (find);
}
