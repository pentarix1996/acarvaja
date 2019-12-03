/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:03:35 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 12:03:50 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_str_str(t_datatype *data, va_list ap)
{
	if (data->val_precission == 0)
	{
		data->datastr = ft_strdup("");
		va_arg(ap, char*);
	}
	else
		data->datastr = va_arg(ap, char *);
	if (!data->datastr)
		data->datastr = "(null)";
	if (data->val_precission < ft_generallen(data) && data->val_precission >= 0)
		data->datastr = ft_substr(data->datastr, 0, data->val_precission);
	if (((int)ft_strlen(data->datastr) >= data->val_precission
			&& !data->fprecision) || (data->fprecision
			&& (int)ft_strlen(data->datastr) < data->val_precission))
		data->result += ft_strlen(data->datastr);
	else
		data->result += data->val_precission;
}

int		do_str_type(t_datatype *data, va_list ap)
{
	if (data->type == string)
		do_str_str(data, ap);
	else if (data->type == character)
	{
		data->fischar = 1;
		data->datachar = va_arg(ap, int);
		data->result += 1;
	}
	else if (data->type == percent)
	{
		data->porcent = '%';
		data->result += 1;
	}
	else if (data->type == pointer)
	{
		data->datapointer = va_arg(ap, long);
		if (data->val_precission == 0)
			data->result += 2;
		else
			data->result += ft_generallen(data) + 2;
	}
	ft_printfnbr(data);
	return (0);
}
