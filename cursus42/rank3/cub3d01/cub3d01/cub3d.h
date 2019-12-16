/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:23:41 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/16 18:37:15 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include "keys.h"
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>

extern int		g_map[15][15];

typedef enum	e_generalcollors
{
	white = 0xFFFFFF,
	red = 0xFF0000,
	green = 0x00FF00,
	blue = 0x0000FF,
	yellow = 0xFFFF00,
	black = 0x000000,
	sky = 0x54F0EB,
	northw = 0xF5D3A2,
	southw = 0x9E8C70,
	eastw = 0xDFCAAA,
	westw = 0xC7B59A,
}				t_generalcollors;

typedef	struct	s_coord
{
	double	x;
	double	y;
}				t_coord;


typedef struct	s_window
{
	int		width;
	int		height;
	void	*w_ptr;
}				t_window;

typedef struct	s_image
{
	char	*data;
	int		bpp; //bits Per Pixel
	int		size;
	int		endian;
}				t_image;

typedef struct	s_mlx
{
	void		*init;
	t_window	win;
	void		*img_ptr;
}				t_mlx;

typedef	struct	s_camera
{
	t_coord	plane;
	double	camerax;
}				t_camera;

typedef struct	s_player
{
	t_coord	pos;
	t_coord	dir;
	double	movespeed;
	double	rotspeed;
}				t_player;

typedef struct	s_data
{
	double	time;
	double	old_time;
}				t_data;

typedef struct	s_key
{
	int		move_up;
	int		move_down;
	int		rotate_left;
	int		rotate_right;
}				t_key;

typedef	struct	s_raycaster
{
	t_coord	raydir;
	int		mapx;
	int		mapy;
	t_coord	sidedist; //length of ray from current position to next x or y-side
	t_coord	deltadist;
	int		stepx; //what direction to step in x or y-direction (either +1 or -1)
	int		stepy;
	int		hit;
	int		side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_raycaster;

typedef struct	s_cb3d
{
	t_mlx		mlx;
	t_image		image;
	t_player	player;
	t_camera	camera;
	t_raycaster	ray;
	t_data		extra;
	t_key		key;
}				t_cb3d;

void		cb3d_set_hooks(t_cb3d *c3d);
int			cb3d_movement(t_cb3d *c3d);
void		do_raycast(t_cb3d *c3d);

#endif