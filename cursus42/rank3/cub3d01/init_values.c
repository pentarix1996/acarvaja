/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:37:09 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:16:12 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	free_test_path(t_cb3d *c3d)
{
	free(c3d->extra.path_ew);
	free(c3d->extra.path_nw);
	free(c3d->extra.path_sw);
	free(c3d->extra.path_table);
	free(c3d->extra.path_ww);
}

int		import_textures(t_cb3d *c3d)
{
	int	a;
	int	b;
	int i;

	a = 64;
	b = 64;
	i = 0;
	c3d->image = malloc(sizeof(t_image) * 7);
	c3d->image[1].ptr = mlx_xpm_file_to_image(c3d->mlx.init,
		c3d->extra.path_nw, &a, &b);
	c3d->image[2].ptr = mlx_xpm_file_to_image(c3d->mlx.init,
		c3d->extra.path_ew, &a, &b);
	c3d->image[3].ptr = mlx_xpm_file_to_image(c3d->mlx.init,
		c3d->extra.path_sw, &a, &b);
	c3d->image[4].ptr = mlx_xpm_file_to_image(c3d->mlx.init,
		c3d->extra.path_ww, &a, &b);
	c3d->image[5].ptr = mlx_xpm_file_to_image(c3d->mlx.init,
		c3d->extra.path_table, &a, &b);
	c3d->image[6].ptr = mlx_xpm_file_to_image(c3d->mlx.init,
		"./textures/greenlight.xpm", &a, &b);
	while (++i < 7)
		c3d->image[i].data = mlx_get_data_addr(c3d->image[i].ptr,
			&c3d->image[i].bpp, &c3d->image[i].size, &c3d->image[i].endian);
	free_test_path(c3d);
	return (1);
}

int		calc_nb_sprites(t_cb3d *c3d)
{
	int j;
	int k;
	int result;

	j = 0;
	result = 0;
	while (j < c3d->ysize)
	{
		k = 0;
		while (k < c3d->xsize)
		{
			if (c3d->g_map[j][k] >= '2' && c3d->g_map[j][k] <= '9')
				result++;
			k++;
		}
		j++;
	}
	return (result);
}

void	init_sprite_data(t_cb3d *c3d)
{
	int j;
	int k;

	c3d->sprite_list = malloc(sizeof(t_sprite) * calc_nb_sprites(c3d));
	j = 0;
	c3d->sprite_count = 0;
	while (j < c3d->ysize)
	{
		k = 0;
		while (k < c3d->xsize)
		{
			if (c3d->g_map[j][k] >= '2' && c3d->g_map[j][k] <= '9')
			{
				c3d->sprite_list[c3d->sprite_count].coord.x = j;
				c3d->sprite_list[c3d->sprite_count].coord.y = k;
				if (c3d->g_map[j][k] == '2')
					c3d->sprite_list[c3d->sprite_count].texture = 5;
				else if (c3d->g_map[j][k] == '3')
					c3d->sprite_list[c3d->sprite_count].texture = 6;
				c3d->sprite_count++;
			}
			k++;
		}
		j++;
	}
}

int		init_cb3d_values(t_cb3d *c3d, char **argv)
{
	int		fd;
	char	*line;
	int		err;

	line = argv[1];
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (fd);
	if (get_next_line(fd, &line) < 0)
		return (0);
	if ((err = put_resolution(line, c3d)) <= 0)
		return (err);
	if ((err = put_textures(fd, line, c3d)) <= 0)
		return (err);
	put_map(fd, line, c3d);
	c3d->mlx.init = mlx_init();
	c3d->mlx.win.w_ptr = mlx_new_window(c3d->mlx.init,
		c3d->mlx.win.width, c3d->mlx.win.height, "Cub3d - acarvaja");
	init_player_data(c3d);
	init_sprite_data(c3d);
	if ((err = import_textures(c3d) < 0))
		return (err);
	c3d->player.movespeed = 0.05;
	c3d->player.rotspeed = 0.03;
	return (1);
}
