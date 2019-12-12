/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:55:24 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/10 12:24:30 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	numspaces_casefp(t_datatype *data)
{
	data->numzeros = data->val_precission - ft_generallen(data);
	if (!data->datastr && !data->porcent)
	{
		if (data->val_precission < ft_generallen(data) && data->val_precission)
			data->numspaces = data->lenght_arg - ft_generallen(data);
		else
			data->numspaces = data->lenght_arg - data->val_precission;
	}
	else
		data->numspaces = data->lenght_arg - ft_generallen(data);
	if (generalnbr(data) < 0)
	{
		data->numzeros++;
		if (data->val_precission > ft_generallen(data))
			data->numspaces--;
	}
}

void	numspaces_casenegp(t_datatype *data)
{
	data->numzeros = data->val_precission - ft_generallen(data);
	if (generalnbr(data) < 0)
	{
		data->numspaces--;
		data->numzeros++;
	}
}

void	numspaces_pointer(t_datatype *data)
{
	if (data->lenght_arg >= (ft_generallen(data) + 2))
		if (data->val_precission == 0)
			data->numspaces = data->lenght_arg - 2;
		else
			data->numspaces = data->lenght_arg - ft_generallen(data) - 2;
	else
		data->numspaces = 0;
}

void	special_cases(t_datatype *data)
{
	if (data->fprecision && !data->val_precission && generalnbr(data))
		data->numspaces = data->lenght_arg - ft_generallen(data);
	else if (data->fprecision && generalnbr(data) < 0)
	{
		if (data->numzeros >= 0)
			data->numspaces = data->lenght_arg - ft_generallen(data)
			- data->numzeros;
		else
			data->numspaces = data->lenght_arg - ft_generallen(data);
	}
	if (data->fspace)
		calc_spaces_fspc(data);
}

void	calc_numspaces(t_datatype *data)
{
	if (!data->fzero)
		data->numspaces = data->lenght_arg - ft_generallen(data) - data->fplus;
	else if (data->fzero)
		data->numzeros = data->lenght_arg - ft_generallen(data) - data->fplus;
	if (data->fprecision && data->val_precission < 0)
		numspaces_casenegp(data);
	if (data->fprecision && data->val_precission >= 0)
		numspaces_casefp(data);
	if (data->fzero && data->fprecision && data->val_precission < 0)
	{
		data->numzeros = 0;
		data->numspaces = data->lenght_arg - ft_generallen(data);
	}
	if ((data->datastr && !data->fzero) || data->datachar)
		data->numzeros = 0;
	if (data->datapointer >= 0 && !data->lenght_arg)
		data->numspaces -= 2;
	else if (data->fpointer && data->lenght_arg)
		numspaces_pointer(data);
	special_cases(data);
}
