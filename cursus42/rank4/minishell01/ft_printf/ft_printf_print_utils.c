/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:21:52 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/10 12:29:28 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nzp(t_datatype *data, va_list ap)
{
	if (!data->fleffield)
		print_spaces(data);
	if (generalnbr(data) >= 0)
	{
		if (data->fplus)
		{
			ft_putchar('+');
			data->result++;
		}
		ft_putgeneral(data, 0, ap);
	}
	else
		ft_putgeneral(data, 1, ap);
	if (data->fleffield)
		print_spaces(data);
}

void	ft_print_znpl(t_datatype *data, va_list ap)
{
	if (data->fspace)
		print_spaces(data);
	if (generalnbr(data) < 0 && !data->fuint)
		ft_putchar('-');
	else if (data->fplus)
	{
		ft_putchar('+');
		data->result++;
	}
	if ((!data->fpercent || !data->fprecision) && !data->fpointer)
		print_zeros(data);
	ft_putgeneral(data, 0, ap);
}

void	ft_print_pvpla(t_datatype *data, va_list ap)
{
	print_spaces(data);
	if (generalnbr(data) < 0 && !data->fuint)
		ft_putchar('-');
	else if (data->fplus)
	{
		ft_putchar('+');
		data->result++;
	}
	if (!data->fpercent && !data->fpointer)
		print_zeros(data);
	ft_putgeneral(data, 0, ap);
}

void	ft_print_lvpp(t_datatype *data, va_list ap)
{
	if (generalnbr(data) < 0 && !data->fuint)
		ft_putchar('-');
	if (!data->fpercent)
		print_zeros(data);
	ft_putgeneral(data, 0, ap);
	print_spaces(data);
}

void	ft_print_zl(t_datatype *data, va_list ap)
{
	data->numspaces = data->numzeros;
	if (generalnbr(data) < 0 && !data->fuint)
		ft_putchar('-');
	ft_putgeneral(data, 0, ap);
	print_spaces(data);
}
