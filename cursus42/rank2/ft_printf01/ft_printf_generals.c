/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_generals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:34:24 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/10 12:33:26 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int		ft_generallen(t_datatype *data)
{
	if (data->datanbr)
		return (ft_intlen(data->datanbr));
	else if (data->dataunbr)
		return (ft_intlen(data->dataunbr));
	else if (data->dataexh)
		return (ft_strlen(ft_atoa_lowexh(data->dataexh)));
	else if (data->dataupexh)
		return (ft_strlen(ft_atoa_upperexh(data->dataupexh)));
	else if (data->datastr)
		return (ft_strlen(data->datastr));
	else if (data->datapointer)
		return (ft_strlen(ft_atoa_lowexh(data->datapointer)));
	return (1);
}

long	generalnbr(t_datatype *data)
{
	if (data->datanbr)
		return (data->datanbr);
	else if (data->dataunbr)
		return (data->dataunbr);
	else if (data->dataexh)
		return (data->dataexh);
	else if (data->dataupexh)
		return (data->dataupexh);
	return (0);
}

void	ft_printstr(t_datatype *data)
{
	if (data->val_precission >= 0)
		ft_putnstr(data->datastr, data->val_precission);
	else
		ft_putstr(data->datastr);
}

void	ft_auxpointer(t_datatype *data)
{
	if (data->fprecision && data->numzeros > 0)
	{
		ft_putstr("0x");
		print_zeros(data);
		ft_putstr(ft_atoa_lowexh(data->datapointer));
	}
	else
		ft_putstr(ft_strjoin("0x", ft_atoa_lowexh(data->datapointer)));
}

void	ft_putgeneral(t_datatype *data, int negativesign, va_list ap)
{
	if (data->datanbr)
		ft_putnbr(generalnbr(data), negativesign);
	else if (data->dataunbr)
		ft_putunbr(generalnbr(data));
	else if (data->dataexh)
		ft_putstr(ft_atoa_lowexh(data->dataexh));
	else if (data->dataupexh)
		ft_putstr(ft_atoa_upperexh(data->dataupexh));
	else if (data->datastr)
		ft_printstr(data);
	else if (data->fpointer)
	{
		if (data->val_precission == 0)
			ft_putstr("0x");
		else
			ft_auxpointer(data);
	}
	else if (data->fischar)
		ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
	else if (data->porcent)
		ft_putchar(data->porcent);
	else if (((data->fprecision && data->val_precission > 0)
				|| !data->fprecision) && !data->fischar)
		ft_putchar('0');
}
