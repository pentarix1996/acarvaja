/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:03:35 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/10 12:30:36 by acarvaja         ###   ########.fr       */
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
		data->result += 1;
	}
	else if (data->type == percent)
	{
		data->fpercent = 1;
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
		data->fpointer = 1;
	}
	ft_printfnbr(data, ap);
	return (0);
}

void	calc_spaces_fspc(t_datatype *data)
{
	if (data->numspaces < 0)
		data->numspaces = 0;
	if ((generalnbr(data) >= 0 && !data->fprecision)
		|| (data->lenght_arg <= 0 && generalnbr(data) >= 0))
	{
		data->numspaces = 1;
		data->numzeros--;
	}
	else if (generalnbr(data) >= 0 && data->fzero)
		data->numspaces = data->lenght_arg - ft_generallen(data)
		- data->numzeros;
	if (!data->fprecision && data->lenght_arg > ft_generallen(data)
		&& !data->fzero)
		data->numspaces = data->lenght_arg - ft_generallen(data);
}
