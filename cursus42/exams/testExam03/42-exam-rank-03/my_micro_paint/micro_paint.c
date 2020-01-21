/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:10:31 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/21 16:39:21 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_zone
{
	int width;
	int height;
	char background;
}				t_zone;

typedef struct	s_shape
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char color;
}				t_shape;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void print_error(char *err)
{
	write(1, err, ft_strlen(err));
}

void free_all(FILE *file, char *drawing)
{
	fclose(file);
	if (drawing)
		free(drawing);
}

int check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300
			&& zone->height > 0 && zone->height <= 300);
}

int get_zone(FILE *file, t_zone *zone)
{
	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background) != 3 || !check_zone(zone))
		return (0);
	return (1);
}

char *paint_background(t_zone *zone)
{
	char *drawing;
	int i;

	if (!(drawing = (char *)malloc((zone->width * zone->height) * sizeof(*drawing))))
		return (NULL);
	i = 0;
	while (i < zone->width * zone->height)
		drawing[i++] = zone->background;
	return (drawing);
}

int check_shapes(t_shape *shape)
{
	return (shape->width > 0.0 && shape->height > 0.0 
			&& (shape->type == 'r' || shape->type == 'R'));
}

int in_rectangle(float x, float y, t_shape *shape)
{
	if (x < shape->x || x > shape->x + shape->width || y < shape->y || y > shape->y + shape->height)
		return (0);
	if (x - shape->x < 1.0 || shape->x + shape->width - x < 1.0 || y - shape->y < 1.0 || shape->y + shape->height - y < 1.0)
		return (2);
	return (1);
}

void draw_shape(char *drawing, t_shape *shape, t_zone *zone)
{
	int i;
	int j;
	int ret;

	i = 0;
	while (i < zone->width)
	{
		j = 0;
		while (j < zone->height)
		{
			ret = in_rectangle(j, i, shape);
			if ((shape->type == 'r' && ret == 2) || (shape->type == 'R' && ret))
				drawing[(i * zone->width) + j] = shape->color;
			j++;
		}
		i++;
	}
}

int draw_shapes(FILE *file, char *drawing, t_zone *zone)
{
	t_shape tmp;
	int scan_ret;

	while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if (!check_shapes(&tmp))
			return (0);
		draw_shape(drawing, &tmp, zone);
	}
	if (scan_ret != -1)
		return (0);
	return (1);
}

void draw_drawing(char *drawing, t_zone *zone)
{
	int i;

	i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	t_zone zone;
	char *drawing;
	FILE *file;

	drawing = NULL;
	file = NULL;
	if (argc == 2)
		if ((file = fopen(argv[1], "r")) && get_zone(file, &zone) && (drawing = paint_background(&zone)) 
			&& draw_shapes(file, drawing, &zone))
			draw_drawing(drawing, &zone);
		else
			print_error("Error: Operation file corrupted\n");
	else
		print_error("Error: argument\n");
	free_all(file, drawing);
	return (0);
}