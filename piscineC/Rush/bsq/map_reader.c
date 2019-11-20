/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:33:25 by atorres-          #+#    #+#             */
/*   Updated: 2019/09/24 15:28:13 by atorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_map_reader(char *strmap, t_map *map)
{
	int	i;
	int	start;
	int error;

	i = 0;
	error = 0;
	start = ft_map_stats(strmap, map);
	map->content = malloc(sizeof(map->content) * map->ysize);
	while (i < map->ysize)
	{
		map->content[i] = malloc(sizeof(t_coord) * (map->xsize));
		i++;
	}
	if (map->xsize > 0 && map->ysize > 0)
	{
		ft_map_lines(strmap, map, start);
		error = 1;
	}
	return (error);
}

int		ft_map_stats(char *strmap, t_map *map)
{
	int i;
	int	x_len;
	int	y_size;

	i = 0;
	y_size = 0;
	while (strmap[i] != '\n')
		i++;
	map->full = strmap[--i];
	map->obst = strmap[--i];
	map->empty = strmap[--i];
	map->ysize = ft_line_count(strmap);
	i = i + 4;
	x_len = 0;
	while (strmap[i] && strmap[i] != '\n')
	{
		x_len++;
		i++;
	}
	i -= x_len + 1;
	map->xsize = x_len;
	return (i + 1);
}

void	ft_map_lines(char *strmap, t_map *map, int start)
{
	int		i;
	int		x;
	int		y;

	i = start;
	x = 0;
	y = 0;
	while (y < map->ysize)
	{
		x = 0;
		while (x < map->xsize)
		{
			map->content[y][x].y = y;
			map->content[y][x].x = x;
			map->content[y][x].fill = strmap[i];
			if (strmap[i] == map->empty)
				map->content[y][x].max_box = -1;
			if (strmap[i] == map->obst)
				map->content[y][x].max_box = 0;
			x++;
			i++;
		}
		i++;
		y++;
	}
}
