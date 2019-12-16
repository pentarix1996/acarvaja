/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 07:23:05 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/16 19:26:11 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_cb3d *c3d)
{
	if (g_map[(int)(c3d->player.pos.x + c3d->player.dir.x * c3d->player.movespeed)][(int)c3d->player.pos.y] == 0)
		c3d->player.pos.x += c3d->player.dir.x * c3d->player.movespeed;
    if (g_map[(int)c3d->player.pos.x][(int)(c3d->player.pos.y + c3d->player.dir.y * c3d->player.movespeed)] == 0)
		c3d->player.pos.y += c3d->player.dir.y * c3d->player.movespeed;
}


void	move_down(t_cb3d *c3d)
{
	if (g_map[(int)(c3d->player.pos.x - c3d->player.dir.x * c3d->player.movespeed)][(int)c3d->player.pos.y] == 0)
		c3d->player.pos.x -= c3d->player.dir.x * c3d->player.movespeed;
    if (g_map[(int)c3d->player.pos.x][(int)(c3d->player.pos.y - c3d->player.dir.y * c3d->player.movespeed)] == 0)
		c3d->player.pos.y -= c3d->player.dir.y * c3d->player.movespeed;
}

void	rotate_left(t_cb3d *c3d)
{
	//both camera direction and camera plane must be rotated
	double old_dirx = c3d->player.dir.x;
	c3d->player.dir.x = c3d->player.dir.x * cos(c3d->player.rotspeed) - c3d->player.dir.y * sin(c3d->player.rotspeed);
	c3d->player.dir.y = old_dirx * sin(c3d->player.rotspeed) + c3d->player.dir.y * cos(c3d->player.rotspeed);
	double old_planex = c3d->camera.plane.x;
	c3d->camera.plane.x = c3d->camera.plane.x * cos(c3d->player.rotspeed) - c3d->camera.plane.y * sin(c3d->player.rotspeed);
	c3d->camera.plane.y = old_planex * sin(c3d->player.rotspeed) + c3d->camera.plane.y * cos(c3d->player.rotspeed);
}

void	rotate_right(t_cb3d *c3d)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = c3d->player.dir.x;
	c3d->player.dir.x = c3d->player.dir.x * cos(-c3d->player.rotspeed) - c3d->player.dir.y * sin(-c3d->player.rotspeed);
	c3d->player.dir.y = oldDirX * sin(-c3d->player.rotspeed) + c3d->player.dir.y * cos(-c3d->player.rotspeed);
	double oldPlaneX = c3d->camera.plane.x;
	c3d->camera.plane.x = c3d->camera.plane.x * cos(-c3d->player.rotspeed) - c3d->camera.plane.y * sin(-c3d->player.rotspeed);
	c3d->camera.plane.y = oldPlaneX * sin(-c3d->player.rotspeed) + c3d->camera.plane.y * cos(-c3d->player.rotspeed);
}

int		cb3d_movement(t_cb3d *c3d)
{
	c3d->player.movespeed = 0.05;
	c3d->player.rotspeed = 0.05;
	if (c3d->key.move_up == 1)
		move_up(c3d);
	if (c3d->key.move_down == 1)
		move_down(c3d);
	if (c3d->key.rotate_left == 1)
		rotate_left(c3d);
	if (c3d->key.rotate_right == 1)
		rotate_right(c3d);
	do_raycast(c3d);
	return (0);
}