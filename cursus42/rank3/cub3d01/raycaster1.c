/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:34:53 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:48:07 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_step_sidedist(t_cb3d *c3d)
{
	if (c3d->ray.raydir.x < 0)
	{
		c3d->ray.stepx = -1;
		c3d->ray.sidedist.x = (c3d->player.pos.x - c3d->ray.mapx)
			* c3d->ray.deltadist.x;
	}
	else
	{
		c3d->ray.stepx = 1;
		c3d->ray.sidedist.x = (c3d->ray.mapx + 1.0 - c3d->player.pos.x)
			* c3d->ray.deltadist.x;
	}
	if (c3d->ray.raydir.y < 0)
	{
		c3d->ray.stepy = -1;
		c3d->ray.sidedist.y = (c3d->player.pos.y - c3d->ray.mapy)
			* c3d->ray.deltadist.y;
	}
	else
	{
		c3d->ray.stepy = 1;
		c3d->ray.sidedist.y = (c3d->ray.mapy + 1.0 - c3d->player.pos.y)
			* c3d->ray.deltadist.y;
	}
}

void	pre_calcs(t_cb3d *c3d, int i)
{
	c3d->camera.camerax = 2 * i / (double)c3d->mlx.win.width - 1;
	c3d->ray.raydir.x = c3d->player.dir.x + c3d->camera.plane.x
		* c3d->camera.camerax;
	c3d->ray.raydir.y = c3d->player.dir.y + c3d->camera.plane.y
		* c3d->camera.camerax;
	c3d->ray.mapx = (int)c3d->player.pos.x;
	c3d->ray.mapy = (int)c3d->player.pos.y;
	c3d->ray.deltadist.x = fabs(1 / c3d->ray.raydir.x);
	c3d->ray.deltadist.y = fabs(1 / c3d->ray.raydir.y);
	c3d->ray.hit = 0;
	calc_step_sidedist(c3d);
}

void	calc_hit(t_cb3d *c3d)
{
	if (c3d->ray.sidedist.x < c3d->ray.sidedist.y)
	{
		c3d->ray.sidedist.x += c3d->ray.deltadist.x;
		c3d->ray.mapx += c3d->ray.stepx;
		c3d->ray.side = 0;
	}
	else
	{
		c3d->ray.sidedist.y += c3d->ray.deltadist.y;
		c3d->ray.mapy += c3d->ray.stepy;
		c3d->ray.side = 1;
	}
	if (c3d->g_map[c3d->ray.mapx][c3d->ray.mapy] == '1')
		c3d->ray.hit = 1;
}

void	one_ray_step(t_cb3d *c3d, int i, double zbuffer[c3d->mlx.win.width])
{
	pre_calcs(c3d, i);
	while (c3d->ray.hit == 0)
		calc_hit(c3d);
	if (c3d->ray.side == 0)
		c3d->ray.wall_dist = (c3d->ray.mapx - c3d->player.pos.x
			+ (1 - c3d->ray.stepx) / 2) / c3d->ray.raydir.x;
	else
		c3d->ray.wall_dist = (c3d->ray.mapy - c3d->player.pos.y
			+ (1 - c3d->ray.stepy) / 2) / c3d->ray.raydir.y;
	c3d->ray.line_height = (int)(c3d->mlx.win.height / c3d->ray.wall_dist);
	c3d->ray.draw_start = -c3d->ray.line_height / 2
		+ c3d->mlx.win.height / 2;
	if (c3d->ray.draw_start < 0)
		c3d->ray.draw_start = 0;
	c3d->ray.draw_end = c3d->ray.line_height / 2 + c3d->mlx.win.height / 2;
	if (c3d->ray.draw_end >= c3d->mlx.win.height)
		c3d->ray.draw_end = c3d->mlx.win.height - 1;
	zbuffer[i] = c3d->ray.wall_dist;
	ft_put_vert_mlx(c3d, i);
}

void	do_raycast(t_cb3d *c3d)
{
	int		i;
	double	zbuffer[c3d->mlx.win.width];

	i = 0;
	c3d->mlx.img_ptr = mlx_new_image(c3d->mlx.init, c3d->mlx.win.width,
		c3d->mlx.win.height);
	c3d->image[0].data = mlx_get_data_addr(c3d->mlx.img_ptr,
		&c3d->image[0].bpp, &c3d->image[0].size, &c3d->image[0].endian);
	while (i < c3d->mlx.win.width)
		one_ray_step(c3d, i++, zbuffer);
	display_sprite(c3d, zbuffer);
	mlx_put_image_to_window(c3d->mlx.init, c3d->mlx.win.w_ptr,
		c3d->mlx.img_ptr, 0, 0);
	mlx_destroy_image(c3d->mlx.init, c3d->mlx.img_ptr);
}
