/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:27:02 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/24 15:05:21 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_limit(t_coord my_coord)
{
	int result;

	result = 1;
	if (my_coord.max_box != 0)
		if (my_coord.x != 0 && my_coord.y != 0)
			result = 0;
	return (result);
}

int		do_algorithm(t_map my_map, t_coord my_cord)
{
	int min;

	min = my_map.content[my_cord.y][my_cord.x - 1].max_box;
	if (my_map.content[my_cord.y - 1][my_cord.x - 1].max_box < min)
		min = my_map.content[my_cord.y - 1][my_cord.x - 1].max_box;
	if (my_map.content[my_cord.y - 1][my_cord.x].max_box < min)
		min = my_map.content[my_cord.y - 1][my_cord.x].max_box;
	min += 1;
	return (min);
}

int		algorithm(t_map my_map, t_coord my_cord)
{
	int result;

	result = 0;
	if (my_cord.max_box != 0)
	{
		if (is_limit(my_cord) == 1)
			result = 1;
		else
			result = do_algorithm(my_map, my_cord);
	}
	return (result);
}
