/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:27:25 by atorres-          #+#    #+#             */
/*   Updated: 2019/09/24 20:05:12 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_map_check(char *mapname)
{
	int		check;

	check = 0;
	check = check + ft_str_is_printable(mapname);
	check = check + ft_lines(mapname);
	check = check + ft_chars(mapname);
	return (check);
}

int		ft_line_count(char *mapname)
{
	int		i;
	int		lines;
	int		n_lines;

	i = 0;
	lines = 0;
	n_lines = 0;
	while (mapname[i] != '\0')
	{
		if (mapname[i] == '\n')
			lines++;
		i++;
	}
	i = 0;
	while (i < (ft_first_line(mapname) - 3))
	{
		n_lines = (n_lines * 10) + (mapname[i] - '0');
		i++;
	}
	if (n_lines != (lines - 1))
		return (-1);
	return (lines - 1);
}

int		ft_first_line(char *mapname)
{
	int		i;

	i = 0;
	while (mapname[i] != '\n' && mapname[i] != '\0')
		i++;
	return (i);
}

int		ft_second_line(char *mapname)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mapname[i] != '\n' && mapname[i] != '\0')
		i++;
	i++;
	while (mapname[i] != '\n' && mapname[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

int		ft_lines(char *mapname)
{
	int		cont[3];

	cont[0] = 0;
	cont[1] = 0;
	cont[2] = 0;
	while (mapname[cont[0]] != '\n' && mapname[cont[0]] != '\0')
		cont[0]++;
	if (mapname[++cont[0]] == '\0')
		return (1);
	while (mapname[cont[0]] != '\0')
	{
		if (mapname[cont[0]] != '\n')
			cont[2]++;
		else
		{
			if (cont[2] != ft_second_line(mapname))
				return (1);
			cont[2] = 0;
		}
		cont[0]++;
	}
	cont[1] = ft_line_count(mapname);
	if (cont[1] < 0)
		return (1);
	return (0);
}
