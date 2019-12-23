/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:37:49 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 19:02:01 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pxl_to_img(t_cb3d *c3d, int x, int y)
{
	int		y_text;
	char	*datac;

	y_text = abs((((y * 256 - c3d->mlx.win.height * 128
		+ c3d->ray.line_height * 128) * 64) / c3d->ray.line_height)
		/ 256);
	datac = &c3d->image[c3d->id].data[y_text % 64 * c3d->image[c3d->id].size +
			c3d->x_text % 64 * c3d->image[c3d->id].bpp / 8];
	ft_memcpy(c3d->image[0].data + 4 * c3d->mlx.win.width * y + x * 4,
			datac, sizeof(int));
}

void	calc_direction_walls(t_cb3d *c3d)
{
	if (c3d->ray.side == 0)
	{
		c3d->x_wall = c3d->player.pos.y + c3d->ray.wall_dist
			* c3d->ray.raydir.y;
		c3d->id = 3;
	}
	else
	{
		c3d->x_wall = c3d->player.pos.x + c3d->ray.wall_dist
			* c3d->ray.raydir.x;
		c3d->id = 4;
	}
	c3d->x_text = (int)(c3d->x_wall * (double)(64));
	if (c3d->ray.side == 0 && c3d->ray.raydir.x > 0)
	{
		c3d->x_text = 64 - c3d->x_text - 1;
		c3d->id = 1;
	}
	if (c3d->ray.side == 1 && c3d->ray.raydir.y < 0)
	{
		c3d->x_text = 64 - c3d->x_text - 1;
		c3d->id = 2;
	}
	c3d->x_text = abs(c3d->x_text);
}

void	ft_put_vert_mlx(t_cb3d *c3d, int x)
{
	int	y;
	int	aux;

	y = c3d->ray.draw_start;
	y = 0;
	while (y < c3d->ray.draw_start)
	{
		aux = c3d->skycolor;
		ft_memcpy(c3d->image[0].data + sizeof(int) * c3d->mlx.win.width
			* y + x * sizeof(int), &aux, sizeof(int));
		y++;
	}
	calc_direction_walls(c3d);
	while (y < c3d->ray.draw_end)
		put_pxl_to_img(c3d, x, y++);
	y = c3d->ray.draw_end;
	if (y < 0)
		y = 0;
	while (y < c3d->mlx.win.height)
	{
		aux = c3d->fcolor;
		ft_memcpy(c3d->image[0].data + sizeof(int) * c3d->mlx.win.width * y + x
			* sizeof(int), &aux, sizeof(int));
		y++;
	}
}

void	display_sprite(t_cb3d *c3d, double zbuffer[c3d->mlx.win.width])
{
	t_dsprite	sprite;
	t_image		*text;
	int			i;

	text = &c3d->image[5];
	i = 0;
	while (i < c3d->sprite_count)
	{
		sort_sprite_distance(c3d, i);
		calc_draw_stripe(c3d, &sprite, i);
		while (sprite.start.x < sprite.end.x)
		{
			sprite.texx = (int)(256 * (sprite.start.x -
				(-sprite.w / 2 + sprite.screenx)) * 64 / sprite.w) / 256;
			if (sprite.transform.y > 0 && sprite.start.x > 0
			&& sprite.start.x < c3d->mlx.win.width
			&& sprite.transform.y < zbuffer[sprite.start.x])
				draw_stripe_sprite(c3d, &sprite, sprite.start.x,
					&c3d->image[c3d->sprite_list[i].texture]);
			sprite.start.x++;
		}
		i++;
	}
}
