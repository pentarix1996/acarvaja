/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:18:11 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/16 19:26:06 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		g_map[15][15] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	init_player_data(t_cb3d *c3d)
{
	c3d->player.pos.x = 3; //PosX que empieza el jugador cambiar
	c3d->player.pos.y = 3; //Cambiar
	c3d->player.dir.x = -1; //DireccionX del jugador
	c3d->player.dir.y = 0; //direccionY del jugador
}

t_cb3d	*init_cb3d_values()
{
	t_cb3d		*c3d;

	if (!(c3d = (t_cb3d *)malloc(sizeof(t_cb3d))))
		ft_putstr("Memory Allocation failed! :`(");
	c3d->mlx.win.width = 700; //Cambiar ancho
	c3d->mlx.win.height = 700;	//Cambiar Alto
	c3d->mlx.init = mlx_init();
	c3d->mlx.win.w_ptr = mlx_new_window(c3d->mlx.init, c3d->mlx.win.width, c3d->mlx.win.height, "Cub3d - acarvaja");
	init_player_data(c3d);
	c3d->camera.plane.x = 0;
	c3d->camera.plane.y = 0.66;
	c3d->extra.time = 0;
	c3d->extra.old_time = 0;
	return (c3d);
}

void	calc_step_sidedist(t_cb3d *c3d)
{
	if (c3d->ray.raydir.x < 0)
	{
		c3d->ray.stepx = -1;
		c3d->ray.sidedist.x = (c3d->player.pos.x - c3d->ray.mapx) * c3d->ray.deltadist.x;
	}
	else
	{
		c3d->ray.stepx = 1;
		c3d->ray.sidedist.x = (c3d->ray.mapx + 1.0 - c3d->player.pos.x) * c3d->ray.deltadist.x;
	}
	if (c3d->ray.raydir.y < 0)
	{
		c3d->ray.stepy = -1;
		c3d->ray.sidedist.y = (c3d->player.pos.y - c3d->ray.mapy) * c3d->ray.deltadist.y;
	}
	else
	{
		c3d->ray.stepy = 1;
		c3d->ray.sidedist.y = (c3d->ray.mapy + 1.0 - c3d->player.pos.y) * c3d->ray.deltadist.y;
	}
}

void ft_put_vert_mlx(t_cb3d *c3d, int x, int color)
{	int y;
	int n;
	int	aux;

	n = 0;
	y = c3d->ray.draw_start;
	(void)color;
	//sky
	while (n < c3d->ray.draw_start)
	{
		aux = sky;
		ft_memcpy(c3d->image.data + sizeof(int) * c3d->mlx.win.width * n + x * sizeof(int), &aux, sizeof(int));
		n++;
	}
	while (y < c3d->ray.draw_end)
	{
		aux = northw;
		ft_memcpy(c3d->image.data + sizeof(int) * c3d->mlx.win.width * y + x * sizeof(int), &aux, sizeof(int));
		y++;
	}
	n = c3d->ray.draw_end;
	//Floor
	while (n < c3d->mlx.win.width)
	{
		aux = white;
		ft_memcpy(c3d->image.data + sizeof(int) * c3d->mlx.win.width * n + x * sizeof(int), &aux, sizeof(int));
		n++;
	}
}

void	do_raycast(t_cb3d *c3d)
{
	int i;
	int color;

	color = northw;
	i = 0;
	c3d->mlx.img_ptr = mlx_new_image(c3d->mlx.init, c3d->mlx.win.width, c3d->mlx.win.height);
	c3d->image.data = mlx_get_data_addr(c3d->mlx.img_ptr, &c3d->image.bpp, \
						&c3d->image.size, &c3d->image.endian);
	while (i < c3d->mlx.win.width)
	{
		//calculate ray position and direction
		c3d->camera.camerax = 2 * i / (double)c3d->mlx.win.width - 1; //x-coordinate in camera space
		c3d->ray.raydir.x = c3d->player.dir.x + c3d->camera.plane.x * c3d->camera.camerax;
		c3d->ray.raydir.y = c3d->player.dir.y + c3d->camera.plane.y * c3d->camera.camerax;
		//which box of the map we're in
		c3d->ray.mapx = (int)c3d->player.pos.x;
		c3d->ray.mapy = (int)c3d->player.pos.y;
		//length of ray from one x or y-side to next x or y-side
		c3d->ray.deltadist.x = fabs(1 / c3d->ray.raydir.x);
		c3d->ray.deltadist.y = fabs(1 / c3d->ray.raydir.y);
		c3d->ray.hit = 0; //was there a wall hit?

		//calculate step and initial sideDist
		calc_step_sidedist(c3d);
		//perform DDA
		while (c3d->ray.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
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
			//Check if ray has hit a wall
			if (g_map[c3d->ray.mapx][c3d->ray.mapy] > 0)
				c3d->ray.hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (c3d->ray.side == 0)
			c3d->ray.wall_dist = (c3d->ray.mapx - c3d->player.pos.x + (1 - c3d->ray.stepx) / 2) / c3d->ray.raydir.x;
		else
			c3d->ray.wall_dist = (c3d->ray.mapy - c3d->player.pos.y + (1 - c3d->ray.stepy) / 2) / c3d->ray.raydir.y;
		//Calculate height of line to draw on screen
		c3d->ray.line_height = (int)(c3d->mlx.win.height / c3d->ray.wall_dist);
		//calculate lowest and highest pixel to fill in current stripe
		c3d->ray.draw_start = -c3d->ray.line_height / 2 + c3d->mlx.win.height / 2;
		if (c3d->ray.draw_start < 0)
			c3d->ray.draw_start = 0;
		c3d->ray.draw_end = c3d->ray.line_height / 2 + c3d->mlx.win.height / 2;
		if (c3d->ray.draw_end >= c3d->mlx.win.height)
			c3d->ray.draw_end = c3d->mlx.win.height - 1;
		//give x and y sides different brightness
		if (c3d->ray.side == 1)
			color /= 2;
		//draw the pixels of the stripe as a vertical line
		ft_put_vert_mlx(c3d, i, color);
		i++;
	}
	mlx_put_image_to_window(c3d->mlx.init, c3d->mlx.win.w_ptr, c3d->mlx.img_ptr, 0, 0);
	mlx_destroy_image(c3d->mlx.init, c3d->mlx.img_ptr);
}

int main()
{
	t_cb3d	*c3d;

	c3d = init_cb3d_values();
	do_raycast(c3d);
	cb3d_set_hooks(c3d);
	mlx_loop(c3d->mlx.init);
	return (0);
}
