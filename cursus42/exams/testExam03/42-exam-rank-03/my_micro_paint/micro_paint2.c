/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:54:52 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/29 16:49:57 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_zone
{
	int height;
	int width;
	char background;
}				t_zone;

typedef struct	s_shape
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char background;
}				t_shape;

void clear_all(FILE *file, char *drawing)
{
	fclose(file);
	if (drawing)
		free(drawing);
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void ft_printerr(char *str)
{
	write(1, str, ft_strlen(str));
}

void draw_drawing(char *drawing, t_zone zone)
{
	int i;

	i = 0;
	while (i < zone.height)
	{
		write(1, drawing + (i * zone.width), zone.width);
		write(1, "\n", 1);
		i++;
	}
}

int check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300
			&& zone->height > 0 && zone->height <= 300);
}

int get_zone(t_zone *zone, FILE *file)
{
	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background) != 3 || !check_zone(zone))
		return (0);
	return (1);
}

char *print_background(t_zone *zone)
{
	char *drawing;
	int i;

	if (!(drawing = (char *)malloc(sizeof(char *) * zone->height * zone->width)))
		return (0);
	i = 0;
	while (i < zone->width * zone->height)
		drawing[i++] = zone->background;
	return (drawing);
}

int check_shape(t_shape shape)
{
	return (shape.width > 0.0 && shape.height > 0.0
			&& (shape.type == 'r' || shape.type == 'R'));
}

int in_rectangle(t_shape shape, float x, float y)
{
	if (x < shape.x || y < shape.y || x > shape.x + shape.width || y > shape.y + shape.height)
		return (0);
	if (x - shape.x < 1.0 || y - shape.y < 1.0 || shape.x + shape.width - x < 1.0 || shape.y + shape.height - y < 1.0)
		return (2);
	return (1);
}

void draw_shape(t_shape shape, char *drawing, t_zone *zone)
{
	int i;
	int j;
	int ret;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			ret = in_rectangle(shape, j, i);
			if ((shape.type == 'r' && ret == 2) || (ret && shape.type == 'R'))
				drawing[(i * zone->width) + j] = shape.background;
			j++;
		}
		i++;
	}
}

int draw_shapes(FILE *file, char *drawing, t_zone *zone)
{
	int ret;
	t_shape tmp;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.background)) == 6)
	{
		if (!check_shape(tmp))
			return (0);
		draw_shape(tmp, drawing, zone);
	}
	if (ret != -1)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	char *drawing;
	FILE *file;
	t_zone zone;

	drawing = 0;
	file = 0;
	if (argc == 2)
	{
		if ((file = fopen(argv[1], "r")) && get_zone(&zone, file) && (drawing = print_background(&zone))
			&& draw_shapes(file, drawing, &zone))
			draw_drawing(drawing, zone);
		else
			ft_printerr("Error: Operation file corrupted\n");
	}
	else
		ft_printerr("Error: argument\n");
	clear_all(file, drawing);
	return (0);
}