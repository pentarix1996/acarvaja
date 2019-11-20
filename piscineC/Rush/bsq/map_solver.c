/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:27:23 by atorres-          #+#    #+#             */
/*   Updated: 2019/09/24 17:35:26 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

t_map	real_fill_map(t_map my_map, t_coord start)
{
	int i;
	int j;

	i = start.y - (start.max_box - 1);
	j = start.x - (start.max_box - 1);
	while (i <= start.y)
	{
		while (j <= start.x)
		{
			my_map.content[i][j].fill = my_map.full;
			j++;
		}
		j = start.x - start.max_box + 1;
		i++;
	}
	return (my_map);
}

t_map	fill_map(t_map my_map)
{
	t_coord	start;
	int		i;
	int		j;

	start = my_map.content[0][0];
	i = 0;
	while (i < my_map.ysize)
	{
		j = 0;
		while (j < my_map.xsize)
		{
			if (my_map.content[i][j].max_box > start.max_box)
				start = my_map.content[i][j];
			j++;
		}
		i++;
	}
	my_map = real_fill_map(my_map, start);
	return (my_map);
}

t_map	resolve_map(t_map m)
{
	int i;
	int j;

	i = 0;
	while (i < m.ysize)
	{
		j = 0;
		while (j < m.xsize)
		{
			m.content[i][j].max_box = algorithm(m, m.content[i][j]);
			j++;
		}
		i++;
	}
	m = fill_map(m);
	return (m);
}

void	print_map(t_map my_map)
{
	int i;
	int j;

	i = 0;
	while (i < my_map.ysize)
	{
		j = 0;
		while (j < my_map.xsize)
		{
			ft_putchar(my_map.content[i][j].fill);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_result(t_map my_map, int i, int argc)
{
	my_map = resolve_map(my_map);
	print_map(my_map);
	if (i < argc - 1)
		ft_putchar('\n');
}
