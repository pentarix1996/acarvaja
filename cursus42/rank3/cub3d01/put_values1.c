/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_values1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:54:49 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:33:51 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_next_spaces(char *line)
{
	while (line && *line == ' ')
		line++;
	return (line);
}

int		put_textures(int fd, char *line, t_cb3d *c3d)
{
	int err;

	if ((err = put_north_text(fd, line, c3d)) < 0)
		return (err);
	if ((err = put_south_text(fd, line, c3d)) < 0)
		return (err);
	if ((err = put_west_text(fd, line, c3d)) < 0)
		return (err);
	if ((err = put_east_text(fd, line, c3d)) < 0)
		return (err);
	if ((err = put_sprite_table(fd, line, c3d)) < 0)
		return (err);
	if ((err = put_floor_color(fd, line, c3d)) < 0)
		return (err);
	if ((err = put_sky_color(fd, line, c3d)) < 0)
		return (err);
	return (1);
}

int		put_resolution2(char *line, t_cb3d *c3d, int i, char *res)
{
	while (line[i] && (line[i] >= '0' && line[i] <= '9'))
		i++;
	ft_strlcpy(res, line, i + 1);
	if (ft_atoi(res) > 2560)
		c3d->mlx.win.width = 2560;
	else
		c3d->mlx.win.width = ft_atoi(res);
	line += i;
	line = trim_next_spaces(line);
	if (*line < '0' || *line > '9')
		return (-1);
	else
	{
		i = 0;
		res = malloc(sizeof(res) * 6);
		while (line[i] && (line[i] >= '0' && line[i] <= '9'))
			i++;
		ft_strlcpy(res, line, i + 1);
		if (ft_atoi(res) > 1440)
			c3d->mlx.win.height = 1440;
		else
			c3d->mlx.win.height = ft_atoi(res);
	}
	return (1);
}

int		put_resolution(char *line, t_cb3d *c3d)
{
	int		i;
	int		err;
	char	*res;

	res = malloc(sizeof(res) * 6);
	i = 0;
	if (*line != 'R')
		return (-1);
	else
	{
		line++;
		line = trim_next_spaces(line);
		if (*line < '0' || *line > '9')
			return (-1);
		else
		{
			if ((err = put_resolution2(line, c3d, i, res)) < 0)
				return (err);
		}
	}
	return (1);
}
