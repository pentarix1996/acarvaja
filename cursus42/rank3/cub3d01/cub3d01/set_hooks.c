/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 06:10:13 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/16 19:03:16 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	exit_hook(t_cb3d *c3d)
{
	mlx_destroy_window(c3d->mlx.init, c3d->mlx.win.w_ptr);
	exit(0);
}

static int	key_release_hook(int key, t_cb3d *c3d)
{
	if (key == KEY_ESCAPE)
		exit_hook(c3d);
	else if (key == KEY_W || key == KEY_UP)
		c3d->key.move_up = 0;
	else if (key == KEY_S || key == KEY_DOWN)
		c3d->key.move_down = 0;
	else if (key == KEY_LEFT)
		c3d->key.rotate_left = 0;
	else if (key == KEY_RIGHT)
		c3d->key.rotate_right = 0;
	return (0);
}

int	key_press_hook(int key, t_cb3d *c3d)
{
	if (key == KEY_ESCAPE)
		exit_hook(c3d);
	else if (key == KEY_W || key == KEY_UP)
		c3d->key.move_up = 1;
	else if (key == KEY_S || key == KEY_DOWN)
		c3d->key.move_down = 1;
	else if (key == KEY_LEFT)
		c3d->key.rotate_left = 1;
	else if (key == KEY_RIGHT)
		c3d->key.rotate_right = 1;
	return (0);
}

void		cb3d_set_hooks(t_cb3d *c3d)
{
	mlx_hook(c3d->mlx.win.w_ptr, 2, 0, key_press_hook, c3d);
	mlx_hook(c3d->mlx.win.w_ptr, 3, 0, key_release_hook, c3d);
	mlx_hook(c3d->mlx.win.w_ptr, 17, 0, exit_hook, c3d);
	mlx_loop_hook(c3d->mlx.init, cb3d_movement, c3d);
}
