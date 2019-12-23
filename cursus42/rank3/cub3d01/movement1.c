/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 07:23:05 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 19:10:56 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_cb3d *c3d)
{
	if (c3d->player.movespeed < 0.06)
	{
		if (c3d->g_map[(int)(c3d->player.pos.x + c3d->player.dir.x
			* (c3d->player.movespeed + 0.05))][(int)c3d->player.pos.y] != '1')
			c3d->player.pos.x += c3d->player.dir.x * c3d->player.movespeed;
	}
	else
	{
		if (c3d->g_map[(int)(c3d->player.pos.x + c3d->player.dir.x
			* c3d->player.movespeed)][(int)c3d->player.pos.y] != '1')
			c3d->player.pos.x += c3d->player.dir.x * c3d->player.movespeed;
	}
	if (c3d->g_map[(int)c3d->player.pos.x][(int)(c3d->player.pos.y
		+ c3d->player.dir.y * c3d->player.movespeed)] != '1')
		c3d->player.pos.y += c3d->player.dir.y * c3d->player.movespeed;
}

void	move_down(t_cb3d *c3d)
{
	if (c3d->player.movespeed < 0.06)
	{
		if (c3d->g_map[(int)(c3d->player.pos.x - c3d->player.dir.x
			* (c3d->player.movespeed + 0.05))][(int)c3d->player.pos.y] != '1')
			c3d->player.pos.x -= c3d->player.dir.x * c3d->player.movespeed;
	}
	else
	{
		if (c3d->g_map[(int)(c3d->player.pos.x - c3d->player.dir.x
			* c3d->player.movespeed)][(int)c3d->player.pos.y] != '1')
			c3d->player.pos.x -= c3d->player.dir.x * c3d->player.movespeed;
	}
	if (c3d->g_map[(int)c3d->player.pos.x][(int)(c3d->player.pos.y
		- c3d->player.dir.y * c3d->player.movespeed)] != '1')
		c3d->player.pos.y -= c3d->player.dir.y * c3d->player.movespeed;
}

void	move_left(t_cb3d *c3d)
{
	if (c3d->g_map[(int)(c3d->player.pos.x - c3d->player.dir.y
		* c3d->player.movespeed)][(int)c3d->player.pos.y] != '1')
		c3d->player.pos.x -= c3d->player.dir.y * c3d->player.movespeed;
	if (c3d->g_map[(int)c3d->player.pos.x][(int)(c3d->player.pos.y
		+ c3d->player.dir.x * c3d->player.movespeed)] != '1')
		c3d->player.pos.y += c3d->player.dir.x * c3d->player.movespeed;
}

void	move_right(t_cb3d *c3d)
{
	if (c3d->g_map[(int)(c3d->player.pos.x + c3d->player.dir.y
		* c3d->player.movespeed)][(int)c3d->player.pos.y] != '1')
		c3d->player.pos.x += c3d->player.dir.y * c3d->player.movespeed;
	if (c3d->g_map[(int)c3d->player.pos.x][(int)(c3d->player.pos.y
		- c3d->player.dir.x * c3d->player.movespeed)] != '1')
		c3d->player.pos.y -= c3d->player.dir.x * c3d->player.movespeed;
}

int		cb3d_movement(t_cb3d *c3d)
{
	if (c3d->key.move_up == 1)
		move_up(c3d);
	if (c3d->key.move_down == 1)
		move_down(c3d);
	if (c3d->key.move_left == 1)
		move_left(c3d);
	if (c3d->key.move_right == 1)
		move_right(c3d);
	if (c3d->key.rotate_left == 1)
		rotate_left(c3d);
	if (c3d->key.rotate_right == 1)
		rotate_right(c3d);
	do_raycast(c3d);
	return (0);
}
