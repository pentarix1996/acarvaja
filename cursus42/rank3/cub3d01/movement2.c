/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:08:35 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 19:13:06 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_cb3d *c3d)
{
	double old_dirx;
	double old_planex;

	old_dirx = c3d->player.dir.x;
	old_planex = c3d->camera.plane.x;
	c3d->player.dir.x = c3d->player.dir.x * cos(c3d->player.rotspeed)
		- c3d->player.dir.y * sin(c3d->player.rotspeed);
	c3d->player.dir.y = old_dirx * sin(c3d->player.rotspeed)
		+ c3d->player.dir.y * cos(c3d->player.rotspeed);
	c3d->camera.plane.x = c3d->camera.plane.x * cos(c3d->player.rotspeed)
		- c3d->camera.plane.y * sin(c3d->player.rotspeed);
	c3d->camera.plane.y = old_planex * sin(c3d->player.rotspeed)
		+ c3d->camera.plane.y * cos(c3d->player.rotspeed);
}

void	rotate_right(t_cb3d *c3d)
{
	double old_dirx;
	double old_planex;

	old_dirx = c3d->player.dir.x;
	old_planex = c3d->camera.plane.x;
	c3d->player.dir.x = c3d->player.dir.x * cos(-c3d->player.rotspeed)
		- c3d->player.dir.y * sin(-c3d->player.rotspeed);
	c3d->player.dir.y = old_dirx * sin(-c3d->player.rotspeed)
		+ c3d->player.dir.y * cos(-c3d->player.rotspeed);
	c3d->camera.plane.x = c3d->camera.plane.x * cos(-c3d->player.rotspeed)
		- c3d->camera.plane.y * sin(-c3d->player.rotspeed);
	c3d->camera.plane.y = old_planex * sin(-c3d->player.rotspeed)
		+ c3d->camera.plane.y * cos(-c3d->player.rotspeed);
}
