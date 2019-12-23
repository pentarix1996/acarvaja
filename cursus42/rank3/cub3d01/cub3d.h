/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:23:41 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 19:32:21 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx_opengl/mlx.h"
# include "keys.h"
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef	struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_window
{
	int			width;
	int			height;
	void		*w_ptr;
}				t_window;

typedef struct	s_image
{
	char		*data;
	int			bpp;
	int			size;
	int			endian;
	void		*ptr;
}				t_image;

typedef struct	s_mlx
{
	void		*init;
	t_window	win;
	void		*img_ptr;
}				t_mlx;

typedef	struct	s_camera
{
	t_coord		plane;
	double		camerax;
}				t_camera;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	double		movespeed;
	double		rotspeed;
}				t_player;

typedef struct	s_data
{
	char		*path_nw;
	char		*path_sw;
	char		*path_ww;
	char		*path_ew;
	char		*path_table;
	char		*path_light;
}				t_data;

typedef struct	s_key
{
	int			move_up;
	int			move_down;
	int			rotate_left;
	int			rotate_right;
	int			move_left;
	int			move_right;
}				t_key;

typedef	struct	s_raycaster
{
	t_coord		raydir;
	int			mapx;
	int			mapy;
	t_coord		sidedist;
	t_coord		deltadist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_raycaster;

typedef struct	s_sprite
{
	t_coord		coord;
	int			texture;
	double		distance;
	t_coord		pos;
	t_coord		dir;
}				t_sprite;

typedef struct	s_dsprite
{
	t_coord		transform;
	t_pos		start;
	t_pos		end;
	int			h;
	int			w;
	int			texx;
	int			screenx;
}				t_dsprite;

typedef struct	s_cb3d
{
	t_mlx		mlx;
	t_image		*image;
	t_player	player;
	t_camera	camera;
	t_raycaster	ray;
	t_data		extra;
	t_key		key;
	int			id;
	double		x_wall;
	int			x_text;
	int			fcolor;
	int			skycolor;
	char		**g_map;
	int			xsize;
	int			ysize;
	t_sprite	*sprite_list;
	int			sprite_count;
}				t_cb3d;

void			cb3d_set_hooks(t_cb3d *c3d);
int				cb3d_movement(t_cb3d *c3d);
void			do_raycast(t_cb3d *c3d);
int				init_cb3d_values(t_cb3d *c3d, char **argv);
char			*trim_next_spaces(char *line);
int				put_resolution(char *line, t_cb3d *c3d);
int				put_textures(int fd, char *line, t_cb3d *c3d);
int				put_north_text(int fd, char *line, t_cb3d *c3d);
int				put_south_text(int fd, char *line, t_cb3d *c3d);
int				put_west_text(int fd, char *line, t_cb3d *c3d);
int				put_east_text(int fd, char *line, t_cb3d *c3d);
int				put_sprite_table(int fd, char *line, t_cb3d *c3d);
char			*next_coma(char *line, char *aux);
int				put_floor_color(int fd, char *line, t_cb3d *c3d);
int				put_sky_color(int fd, char *line, t_cb3d *c3d);
int				bad_format(char	*line);
void			put_map(int fd, char *line, t_cb3d *c3d);
int				ft_strlen_nospaces(char *line);
char			*fill_map(char *line, char *result);
void			one_step(t_cb3d *c3d, int i, int size, char *line);
void			init_player_data(t_cb3d *c3d);
void			do_raycast(t_cb3d *c3d);
void			display_sprite(t_cb3d *c3d, double zbuffer[c3d->mlx.win.width]);
void			draw_stripe_sprite(t_cb3d *c3d, t_dsprite *spr,
					int sp, t_image *img);
void			calc_draw_stripe(t_cb3d *c3d, t_dsprite *sp, int pos);
void			sort_sprite_distance(t_cb3d *c3d, int pos);
void			ft_put_vert_mlx(t_cb3d *c3d, int x);
void			rotate_left(t_cb3d *c3d);
void			rotate_right(t_cb3d *c3d);

#endif
