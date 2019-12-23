/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:57:17 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:17:39 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		bad_format(char *line)
{
	return ((ft_strnstr(line, ".xpm", ft_strlen(line)) ? 1 : -3));
}

int		put_north_text(int fd, char *line, t_cb3d *c3d)
{
	if (get_next_line(fd, &line) < 0)
		return (-2);
	if (*line++ != 'N')
		return (-2);
	if (*line++ != 'O')
		return (-2);
	line = trim_next_spaces(line);
	if (bad_format(line) < 0)
		return (-3);
	c3d->extra.path_nw = malloc(ft_strlen(line) + 1);
	ft_strcpy(c3d->extra.path_nw, line);
	return (1);
}

int		put_south_text(int fd, char *line, t_cb3d *c3d)
{
	if (get_next_line(fd, &line) < 0)
		return (-4);
	if (*line++ != 'S')
		return (-4);
	if (*line++ != 'O')
		return (-4);
	line = trim_next_spaces(line);
	if (bad_format(line) < 0)
		return (-3);
	c3d->extra.path_sw = malloc(ft_strlen(line));
	ft_strcpy(c3d->extra.path_sw, line);
	return (1);
}

int		put_west_text(int fd, char *line, t_cb3d *c3d)
{
	if (get_next_line(fd, &line) < 0)
		return (-5);
	if (*line++ != 'W')
		return (-5);
	if (*line++ != 'E')
		return (-5);
	line = trim_next_spaces(line);
	if (bad_format(line) < 0)
		return (-3);
	c3d->extra.path_ww = malloc(ft_strlen(line));
	ft_strcpy(c3d->extra.path_ww, line);
	return (1);
}

void	put_map(int fd, char *line, t_cb3d *c3d)
{
	int i;

	i = 0;
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	c3d->xsize = ft_strlen_nospaces(line);
	c3d->ysize = 1;
	c3d->g_map = malloc(sizeof(char *) * c3d->ysize);
	one_step(c3d, i++, c3d->xsize, line);
	while (get_next_line(fd, &line))
	{
		c3d->ysize++;
		c3d->g_map = realloc(c3d->g_map, sizeof(char *) * c3d->ysize);
		one_step(c3d, i++, c3d->xsize, line);
	}
	c3d->ysize++;
	c3d->g_map = realloc(c3d->g_map, sizeof(char *) * c3d->ysize);
	one_step(c3d, i++, c3d->xsize, line);
}
