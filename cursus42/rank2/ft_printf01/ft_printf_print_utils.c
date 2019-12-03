/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:21:52 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 12:22:46 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nzp(t_datatype *data)
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
		ft_putgeneral(data, 0);
	}
	else
		ft_putgeneral(data, 1);
	if (data->fleffield)
		print_spaces(data);
}

void	ft_print_znpl(t_datatype *data)
{
	if (generalnbr(data) < 0)
		ft_putchar('-');
	else if (data->fplus)
	{
		ft_putchar('+');
		data->result++;
	}
	print_zeros(data);
	ft_putgeneral(data, 0);
}

void	ft_print_pvpla(t_datatype *data)
{
	print_spaces(data);
	if (generalnbr(data) < 0)
		ft_putchar('-');
	else if (data->fplus)
	{
		ft_putchar('+');
		data->result++;
	}
	print_zeros(data);
	ft_putgeneral(data, 0);
}

void	ft_print_lvpp(t_datatype *data)
{
	if (generalnbr(data) < 0)
		ft_putchar('-');
	print_zeros(data);
	ft_putgeneral(data, 0);
	print_spaces(data);
}

void	ft_print_zl(t_datatype *data)
{
	data->numspaces = data->numzeros;
	if (generalnbr(data) < 0)
		ft_putchar('-');
	ft_putgeneral(data, 0);
	print_spaces(data);
}
