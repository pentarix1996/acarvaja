/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:35:31 by atorres-          #+#    #+#             */
/*   Updated: 2019/09/24 19:56:06 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_coord
{
	int		x;
	int		y;
	int		max_box;
	char	fill;
}				t_coord;
typedef	struct	s_map
{
	int		xsize;
	int		ysize;
	char	empty;
	char	obst;
	char	full;
	t_coord	**content;
}				t_map;
/*
** comunes.c
*/
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
void			ft_putstr(char *str);
void			ft_putchar(char letter);
int				ft_str_is_printable(char *str);
/*
** comunes2.c
*/
char			*ft_stdin_reader(char *read, char c, int size);
/*
** map_reader.c
*/
int				ft_map_reader(char *strmap, t_map *map);
int				ft_map_stats(char *strmap, t_map *map);
void			ft_map_lines(char *strmap, t_map *map, int start);
/*
** map_solver.c
*/
t_map			fill_example_map();
void			print_result(t_map my_map, int i, int argc);
void			print_map(t_map my_map);
t_map			resolve_map(t_map m);
t_map			fill_map(t_map my_map);
t_map			real_fill_map(t_map my_map, t_coord start);
/*
** algorithm.c
*/
int				algorithm(t_map my_map, t_coord my_cord);
int				do_algorithm(t_map my_map, t_coord my_cord);
int				is_limit(t_coord my_coord);
/*
** file_reader.c
*/
int				ft_file_size(char *name);
char			*ft_file_read(char *name, int file_size);
/*
** map_checker.c
*/
int				ft_map_check(char *mapname);
int				ft_line_count(char *mapname);
int				ft_first_line(char *mapname);
int				ft_second_line(char *mapname);
int				ft_lines(char *mapname);
/*
** map_checker2.c
*/
int				ft_chars(char *mapname);
int				ft_finder(char *mapname, char *key);

#endif
