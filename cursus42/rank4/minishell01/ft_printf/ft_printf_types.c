/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:20:56 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/12 19:34:49 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_type(t_datatype *data)
{
	while (*data->format && *data->format != percent)
	{
		ft_putchar(*data->format++);
		data->result++;
	}
}

t_types	*fill_types(t_types *my_list_types)
{
	my_list_types[0] = string;
	my_list_types[1] = character;
	my_list_types[2] = pointer;
	my_list_types[3] = decimal;
	my_list_types[4] = integer;
	my_list_types[5] = unsgint;
	my_list_types[6] = exhlower;
	my_list_types[7] = exhupper;
	my_list_types[8] = percent;
	my_list_types[9] = '\0';
	return (my_list_types);
}

int		is_correct_type(char type)
{
	int		result;
	t_types	*all_types;
	t_types	*aux_list;

	if ((all_types = malloc(sizeof(all_types) * 10)))
	{
		all_types = fill_types(all_types);
		aux_list = all_types;
	}
	else
		return (-1);
	while (*aux_list != '\0')
	{
		if (type == (char)*aux_list)
			break ;
		aux_list++;
	}
	result = *aux_list;
	free(all_types);
	return (result);
}

int		is_numerical_type(char type)
{
	return (type == decimal || type == integer || type == unsgint
			|| type == exhlower || type == exhupper);
}

int		is_flag(char flag)
{
	return (flag == zero || flag == leffield || flag == takearg
			|| flag == precision || (flag > '0' && flag <= '9')
			|| flag == plus || flag == space);
}
