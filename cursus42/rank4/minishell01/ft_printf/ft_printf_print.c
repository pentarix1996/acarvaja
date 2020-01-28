/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:39:07 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/10 12:26:19 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long nbr)
{
	int i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int		ft_uintlen(unsigned int nbr)
{
	int i;

	i = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	print_spaces(t_datatype *data)
{
	while (data->numspaces-- > 0)
	{
		ft_putchar(' ');
		data->result++;
	}
}

void	print_zeros(t_datatype *data)
{
	while (data->numzeros-- > 0)
	{
		ft_putchar('0');
		data->result++;
	}
}

void	ft_printfnbr(t_datatype *data, va_list ap)
{
	calc_numspaces(data);
	if ((!data->fzero && !data->fprecision) ||
			(data->fzero && data->fprecision && data->val_precission < 0))
		ft_print_nzp(data, ap);
	else if ((data->fzero && !data->fprecision && !data->fleffield) ||
			(data->val_precission >= 0 && !data->lenght_arg
			&& data->fprecision))
		ft_print_znpl(data, ap);
	else if (data->fprecision && data->val_precission >= 0 && data->lenght_arg
			&& !data->fleffield)
		ft_print_pvpla(data, ap);
	else if (data->fleffield && data->val_precission >= 0 && data->fprecision)
		ft_print_lvpp(data, ap);
	else if (data->fzero && data->fleffield)
		ft_print_zl(data, ap);
}
