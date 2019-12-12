/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:42:35 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/04 19:38:13 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_flags_takearg(t_datatype *data, va_list ap)
{
	if (!data->fprecision)
	{
		data->lenght_arg = va_arg(ap, int);
		if (data->lenght_arg < 0)
		{
			data->fleffield = 1;
			data->lenght_arg *= -1;
		}
	}
	else
	{
		data->val_precission = va_arg(ap, int);
		if (data->val_precission < 0)
			data->fprecision = 0;
	}
}

void	read_flags_larg(t_datatype *data, int *move)
{
	if (*data->format > '0' && *data->format <= '9' && !data->fprecision)
	{
		*move = 0;
		data->lenght_arg = *data->format++ - '0';
	}
	while (*data->format >= '0' && *data->format <= '9' && !data->fprecision)
		data->lenght_arg = (data->lenght_arg * 10) + (*data->format++ - '0');
}

void	read_flags_lpre(t_datatype *data, int *move)
{
	if (*data->format >= '0' && *data->format <= '9' && data->fprecision)
	{
		*move = 0;
		data->val_precission = *data->format++ - '0';
	}
	while (*data->format >= '0' && *data->format <= '9' && data->fprecision)
		data->val_precission = (data->val_precission * 10)
			+ (*data->format++ - '0');
}

int		read_flag(t_datatype *data, va_list ap)
{
	int move;

	move = 1;
	if (*data->format == plus)
		data->fplus = 1;
	else if (*data->format == leffield)
		data->fleffield = 1;
	else if (*data->format == space)
		data->fspace = 1;
	else if (*data->format == zero && !data->fprecision)
	{
		data->fzero = 1;
		return (move);
	}
	else if (*data->format == precision)
	{
		data->fprecision = 1;
		data->val_precission = 0;
	}
	else if (*data->format == takearg)
		read_flags_takearg(data, ap);
	read_flags_larg(data, &move);
	read_flags_lpre(data, &move);
	return (move);
}
