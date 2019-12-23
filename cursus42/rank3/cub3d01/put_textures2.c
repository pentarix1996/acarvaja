/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:59:24 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:18:20 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*next_coma(char *line, char *aux)
{
	int i;

	i = 0;
	while (*line && *line != ',')
		aux[i++] = *line++;
	return (line);
}

int		put_east_text(int fd, char *line, t_cb3d *c3d)
{
	if (get_next_line(fd, &line) < 0)
		return (-6);
	if (*line++ != 'E')
		return (-6);
	if (*line++ != 'A')
		return (-6);
	line = trim_next_spaces(line);
	if (bad_format(line) < 0)
		return (-3);
	c3d->extra.path_ew = malloc(ft_strlen(line));
	ft_strcpy(c3d->extra.path_ew, line);
	return (1);
}

int		put_sprite_table(int fd, char *line, t_cb3d *c3d)
{
	get_next_line(fd, &line);
	if (get_next_line(fd, &line) < 0)
		return (-8);
	if (*line++ != 'S')
		return (-8);
	line = trim_next_spaces(line);
	if (bad_format(line) < 0)
		return (-3);
	c3d->extra.path_table = malloc(ft_strlen(line));
	ft_strcpy(c3d->extra.path_table, line);
	return (1);
}

int		put_floor_color(int fd, char *line, t_cb3d *c3d)
{
	int		*rgb;
	char	*aux;

	if (get_next_line(fd, &line) < 0)
		return (-7);
	if (*line++ != 'F')
		return (-7);
	line = trim_next_spaces(line);
	aux = malloc(sizeof(char *) * 4);
	rgb = malloc(sizeof(int *) * 3);
	line = next_coma(line, aux);
	line++;
	rgb[0] = ft_atoi(aux);
	line = next_coma(line, aux);
	rgb[1] = ft_atoi(aux);
	line++;
	line = next_coma(line, aux);
	rgb[2] = ft_atoi(aux);
	free(aux);
	c3d->fcolor = (rgb[0] * 0x10000) + (rgb[1] * 0x100) + rgb[2];
	free(rgb);
	return (1);
}

int		put_sky_color(int fd, char *line, t_cb3d *c3d)
{
	int		*rgb;
	char	*aux;

	if (get_next_line(fd, &line) < 0)
		return (-7);
	if (*line++ != 'C')
		return (-7);
	line = trim_next_spaces(line);
	aux = malloc(sizeof(char *) * 4);
	rgb = malloc(sizeof(int *) * 3);
	line = next_coma(line, aux);
	line++;
	rgb[0] = ft_atoi(aux);
	line = next_coma(line, aux);
	rgb[1] = ft_atoi(aux);
	line++;
	line = next_coma(line, aux);
	rgb[2] = ft_atoi(aux);
	free(aux);
	c3d->skycolor = (rgb[0] * 0x10000) + (rgb[1] * 0x100) + rgb[2];
	free(rgb);
	return (1);
}
