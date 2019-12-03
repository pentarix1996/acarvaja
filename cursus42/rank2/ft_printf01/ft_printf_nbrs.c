/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:48:17 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 11:49:47 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	do_num_dandi(t_datatype *data, va_list ap)
{
	data->datanbr = va_arg(ap, int);
	if ((!data->fprecision || data->val_precission > 0))
		data->result += ft_intlen((long)data->datanbr);
}

void	do_num_u(t_datatype *data, va_list ap)
{
	data->dataunbr = va_arg(ap, unsigned int);
	if ((!data->fprecision || data->val_precission > 0))
		data->result += ft_uintlen(data->dataunbr);
}

void	do_num_exhl(t_datatype *data, va_list ap)
{
	data->dataexh = va_arg(ap, unsigned long);
	if ((!data->fprecision || data->val_precission > 0))
		data->result += ft_strlen(ft_atoa_lowexh(data->dataexh));
}

void	do_num_exhu(t_datatype *data, va_list ap)
{
	data->dataupexh = va_arg(ap, unsigned long);
	if ((!data->fprecision || data->val_precission > 0))
		data->result += ft_strlen(ft_atoa_upperexh(data->dataupexh));
}

int		do_num_type(t_datatype *data, va_list ap)
{
	if (data->type == decimal || data->type == integer)
		do_num_dandi(data, ap);
	else if (data->type == unsgint)
		do_num_u(data, ap);
	else if (data->type == exhlower)
		do_num_exhl(data, ap);
	else if (data->type == exhupper)
		do_num_exhu(data, ap);
	ft_printfnbr(data);
	return (0);
}
