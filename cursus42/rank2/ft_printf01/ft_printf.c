/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:18:10 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 12:08:03 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void		one_jump_data(t_datatype *data)
{
	if (*data->format)
		data->format++;
}

int			do_complex(t_datatype *data, va_list ap)
{
	next_type(data);
	data->format++;
	while (*data->format)
	{
		while (is_flag(*data->format))
			data->format += read_flag(data, ap);
		if ((data->type = is_correct_type(*data->format)))
		{
			if (is_numerical_type(data->type))
			{
				if (do_num_type(data, ap) == -1)
					return (-1);
			}
			else
			{
				if (do_str_type(data, ap) == -1)
					return (-1);
			}
			data->format += 1;
		}
		data = resetdata(data);
		next_type(data);
		one_jump_data(data);
	}
	return (data->result);
}

int			do_simple(const char *format)
{
	ft_putstr(format);
	return (ft_strlen(format));
}

int			is_simple(const char *format)
{
	return (!(ft_strchr(format, percent)) ? 1 : 0);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_datatype	*data;
	int			result;

	data = 0;
	data = inidata(data);
	data->format = (char *)format;
	va_start(ap, format);
	if (!is_simple(format))
		result = do_complex(data, ap);
	va_end(ap);
	free(data);
	return (is_simple(format) ? do_simple(format) : result);
}
