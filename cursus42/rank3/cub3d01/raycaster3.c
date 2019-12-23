/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:55:44 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 19:06:02 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite_distance(t_cb3d *c3d, int pos)
{
	c3d->sprite_list[pos].distance = ((c3d->player.pos.x
		- c3d->sprite_list[pos].coord.x) * (c3d->player.pos.x
		- c3d->sprite_list[pos].coord.x) + (c3d->player.pos.y
		- c3d->sprite_list[pos].coord.y) * (c3d->player.pos.y
		- c3d->sprite_list[pos].coord.y));
}

void	calc_draw_stripe2(t_cb3d *c3d, t_dsprite *sp)
{
	if (sp->end.y >= c3d->mlx.win.height)
		sp->end.y = c3d->mlx.win.height - 1;
	sp->w = abs((int)(c3d->mlx.win.height / (sp->transform.y)));
	sp->screenx = (int)((c3d->mlx.win.width / 2)
		* (1 + sp->transform.x / sp->transform.y));
	sp->start.x = -sp->w / 2 + sp->screenx;
	if (sp->start.x < 0)
		sp->start.x = 0;
	sp->end.x = sp->w / 2 + sp->screenx;
	if (sp->end.x >= c3d->mlx.win.width)
		sp->end.x = c3d->mlx.win.width - 1;
}

void	calc_draw_stripe(t_cb3d *c3d, t_dsprite *sp, int pos)
{
	double		inv;
	t_coord		spritepos;

	spritepos.x = (c3d->sprite_list[pos].coord.x) - c3d->player.pos.x;
	spritepos.y = (c3d->sprite_list[pos].coord.y) - c3d->player.pos.y;
	inv = 1.0 / (c3d->camera.plane.x * c3d->player.dir.y - c3d->player.dir.x
		* c3d->camera.plane.y);
	sp->transform.x = inv * (c3d->player.dir.y * spritepos.x - c3d->player.dir.x
		* spritepos.y);
	sp->transform.y = inv * (-c3d->camera.plane.y * spritepos.x
		+ c3d->camera.plane.x * spritepos.y);
	sp->h = abs((int)(c3d->mlx.win.height / sp->transform.y));
	sp->start.y = -sp->h / 2 + c3d->mlx.win.height / 2;
	sp->start.y = (sp->start.y < 0) ? 0 : sp->start.y;
	sp->end.y = sp->h / 2 + c3d->mlx.win.height / 2;
	calc_draw_stripe2(c3d, sp);
}

void	draw_stripe_sprite(t_cb3d *c3d, t_dsprite *spr, int sp, t_image *img)
{
	int texelw;
	int texelt;
	int y;
	int d;
	int texy;

	y = spr->start.y;
	while (y < spr->end.y)
	{
		d = (y * 256) - ((c3d->mlx.win.height) * 128) + (spr->h * 128);
		texy = ((d * 64) / spr->h) / 256;
		texelw = (sp * (c3d->image->bpp / 8)) + (y * c3d->image->size);
		texelt = (spr->texx * (img->bpp / 8)) + (texy * img->size);
		if (img->data[texelt] != 0 || img->data[texelt + 1] != 0
			|| img->data[texelt + 2] != 0)
		{
			c3d->image->data[texelw] = img->data[texelt];
			c3d->image->data[texelw + 1] = img->data[texelt + 1];
			c3d->image->data[texelw + 2] = img->data[texelt + 2];
		}
		y++;
	}
}
