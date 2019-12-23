/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_values2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:06:55 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:34:06 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen_nospaces(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line++ != ' ')
			i++;
	}
	return (i);
}

void	one_step(t_cb3d *c3d, int i, int size, char *line)
{
	c3d->g_map[i] = malloc(sizeof(char) * (size + 1));
	c3d->g_map[i] = fill_map(line, c3d->g_map[i]);
}

char	*fill_map(char *line, char *result)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line != ' ')
		{
			result[i] = *line;
			i++;
		}
		line++;
	}
	return (result);
}

void	init_player_pos(t_cb3d *c3d, int j, int k)
{
	c3d->player.dir.y = 0;
	c3d->player.dir.x = -1;
	c3d->camera.plane.x = 0;
	c3d->camera.plane.y = 0.66;
	if (c3d->g_map[j][k] == 'S')
	{
		c3d->camera.plane.y = -0.66;
		c3d->player.dir.x = 1;
	}
	else if (c3d->g_map[j][k] == 'W')
	{
		c3d->camera.plane.x = -0.66;
		c3d->camera.plane.y = 0;
		c3d->player.dir.x = 0;
	}
	else if (c3d->g_map[j][k] == 'E')
	{
		c3d->camera.plane.y = 0;
		c3d->player.dir.x = 0;
		c3d->player.dir.y = 1;
	}
}

void	init_player_data(t_cb3d *c3d)
{
	int j;
	int k;
	int flag;

	j = 0;
	flag = 0;
	while (j < c3d->ysize && !flag)
	{
		k = 0;
		while (k < c3d->xsize && !flag)
		{
			if (c3d->g_map[j][k] == 'N' || c3d->g_map[j][k] == 'S'
				|| c3d->g_map[j][k] == 'W' || c3d->g_map[j][k] == 'E')
			{
				c3d->player.pos.x = j;
				c3d->player.pos.y = k;
				flag = 1;
			}
			k++;
		}
		j++;
	}
	init_player_pos(c3d, j, k);
}
