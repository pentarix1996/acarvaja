/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:42:35 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/30 10:17:12 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnstr(const char *str, int i)
{
	while (*str && i-- > 0)
		ft_putchar(*str++);
}

void	next_type(t_datatype *data)
{
	while (*data->format && *data->format != percent)
	{
		ft_putchar(*data->format++);
		data->result++;
	}
}

t_types	*fill_types(t_types *my_list_types)
{
	my_list_types[0] = string;
	my_list_types[1] = character;
	my_list_types[2] = pointer;
	my_list_types[3] = decimal;
	my_list_types[4] = integer;
	my_list_types[5] = unsgint;
	my_list_types[6] = exhlower;
	my_list_types[7] = exhupper;
	my_list_types[8] = percent;
	my_list_types[9] = '\0';
	return my_list_types;
}

int		is_correct_type(char type)
{
	int result;
	t_types *all_types;
	t_types *aux_list;

	if ((all_types = malloc(sizeof(all_types) * 10)))
	{
		all_types = fill_types(all_types);
		aux_list = all_types;
	}
	else
		return (-1);
	while (*aux_list != '\0')
	{
		
		if (type == *aux_list)
			break;
		aux_list++;
	}
	result = *aux_list;
	free(all_types);
	return (result);
}

int		is_numerical_type(char type)
{
	return (type == decimal || type == integer || type == unsgint
			|| type == exhlower || type == exhupper);
}

void	ft_swap(char *a, char *b)
{
	char swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

char	*revert(char *ptr)
{
	int j;
	int i;
	int k;

	i = 0;
	j = 0;
	while (ptr[j] != '\0')
		j++;
	k = j;
	j -= 1;
	if(ptr[0] == '-')
	{
		while (++i < k/2 + 1)
			ft_swap(&ptr[i], &ptr[j--]);
	}
	else
	{
		while (i < k/2)
			ft_swap(&ptr[i++], &ptr[j--]);
	}
	return(ptr);
}

char	*ft_atoa_lowexh(unsigned long nbr)
{
	char	*result;
	char	*pos;
	int		i;

	pos = "0123456789abcdef";
	result = malloc(sizeof(*result) * 16);
	i = 0;
	while (nbr >= 16)
	{
		result[i++] = pos[nbr % 16];
		nbr /= 16;
	}
	result[i] = pos[nbr % 16];
	revert(result);
	return (result);
}

char	*ft_atoa_upperexh(unsigned long nbr)
{
	char	*result;
	char	*pos;
	int		i;

	pos = "0123456789ABCDEF";
	result = malloc(sizeof(*result) * 16);
	i = 0;
	while (nbr >= 16)
	{
		result[i++] = pos[nbr % 16];
		nbr /= 16;
	}
	result[i] = pos[nbr % 16];
	revert(result);
	return (result);
}

void	ft_putnbr(int nb, int singneg)
{
	if (nb != -2147483648)
	{
		if (nb < 10 && nb >= 0)
		{
			ft_putchar(nb + '0');
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10, singneg);
			ft_putchar(nb % 10 + '0');
		}
		else
		{
			if (singneg)
				ft_putchar('-');
			ft_putnbr(nb * -1, singneg);
		}
	}
	else
		write(1, "-2147483648", 11);
}

int		ft_intlen(int nbr)
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

int		generalnbr(t_datatype *data)
{
	if (data->datanbr)
		return (data->datanbr);
	else if (data->dataunbr)
		return (data->dataunbr);
	return (0);
}

void	calc_numspaces(t_datatype *data)
{
	if (!data->fzero)
		data->numspaces = data->lenght_arg - ft_generallen(data);
	else if(data->fzero)
		data->numzeros = data->lenght_arg - ft_generallen(data);
	if (data->fprecision && !data->val_precission)
	{
		data->numzeros = data->val_precission - ft_generallen(data);
		if (generalnbr(data) < 0)
		{
			data->numspaces--;
			data->numzeros++;
		}
	}
	if (data->fprecision && data->val_precission)
	{
		data->numzeros = data->val_precission - ft_generallen(data);
		if (ft_generallen(data) > data->val_precission && !data->datastr)
			data->val_precission = ft_generallen(data);
		data->numspaces = data->lenght_arg - data->val_precission;
		if (generalnbr(data) < 0)
		{
			data->numspaces--;
			data->numzeros++;
		}
	}
	if (data->fzero && data->fprecision && !data->val_precission)
	{
		data->numzeros = 0;
		data->numspaces = data->lenght_arg - ft_generallen(data);
	}
	if (data->datastr || data->datachar)
		data->numzeros = 0;
	if (data->datapointer >= 0 && !data->lenght_arg)
		data->numspaces -= 2;
	else if (data->datapointer >= 0 && data->lenght_arg)
	{
		if (data->lenght_arg >= (ft_generallen(data) + 2))
		{
			data->numspaces = data->lenght_arg - ft_generallen(data) - 2;
		}
		else
			data->numspaces = 0;		
	}
}

void	ft_putgeneral(t_datatype *data, int negativesign)
{
	if (data->datanbr || data->dataunbr)
		ft_putnbr(generalnbr(data), negativesign);
	else if (data->dataexh)
		ft_putstr(ft_atoa_lowexh(data->dataexh));
	else if (data->dataupexh)
		ft_putstr(ft_atoa_upperexh(data->dataupexh));
	else if (data->datastr)
	{
		if (data->val_precission)
			ft_putnstr(data->datastr, data->val_precission);
		else
			ft_putstr(data->datastr);		
	}
	else if (data->datachar)
		ft_putchar(data->datachar);
	else if (data->datapointer >= 0)
		ft_putstr(ft_strjoin("0x", ft_atoa_lowexh(data->datapointer)));
	else
		ft_putchar('0');	
}

void	ft_printfnbr(t_datatype *data)
{
	calc_numspaces(data);
	if ((!data->fzero && !data->fprecision) || 
			(data->fzero && data->fprecision && !data->val_precission))
	{
		if (!data->fleffield)
			print_spaces(data);
		if (generalnbr(data) >= 0)
			ft_putgeneral(data, 0);
		else
			ft_putgeneral(data, 1);
		if (data->fleffield)
			print_spaces(data);
	}
	else if ((data->fzero && !data->fprecision) || 
			(data->val_precission && !data->lenght_arg && data->fprecision))
	{
		if (generalnbr(data) < 0)
			ft_putchar('-');
		print_zeros(data);
		ft_putgeneral(data, 0);
	}
	else if (data->fprecision && data->val_precission && data->lenght_arg && !data->fleffield)
	{
		print_spaces(data);
		if (generalnbr(data) < 0)
			ft_putchar('-');
		print_zeros(data);
		ft_putgeneral(data, 0);
	}
	else if (data->fleffield && data->val_precission && data->fleffield && data->fprecision)
	{
		if (generalnbr(data) < 0)
			ft_putchar('-');
		print_zeros(data);
		ft_putgeneral(data, 0);
		print_spaces(data);
	}
}

int		do_num_type(t_datatype *data, va_list ap)
{
	if (data->type == decimal || data->type == integer)
	{
		data->datanbr = va_arg(ap, int);
		data->result += ft_intlen(data->datanbr);
	}
	else if (data->type == unsgint)
	{
		data->dataunbr = va_arg(ap, unsigned int);
		data->result += ft_uintlen(data->dataunbr);
	}
	else if (data->type == exhlower)
	{
		data->dataexh = va_arg(ap, unsigned long);
		data->result += ft_strlen(ft_atoa_lowexh(data->dataexh));
	}
	else if (data->type == exhupper)
	{
		data->dataupexh = va_arg(ap, unsigned long);
		data->result += ft_strlen(ft_atoa_upperexh(data->dataupexh));
	}
	ft_printfnbr(data);
	return (0);
}

int		do_str_type(t_datatype *data, va_list ap)
{
	if (data->type == string)
	{
		data->datastr = va_arg(ap, char *);
		if (!data->datastr)
			data->datastr = "(null)";
		if (((int)ft_strlen(data->datastr) >= data->val_precission && !data->fprecision)
			|| (data->fprecision && (int)ft_strlen(data->datastr) < data->val_precission))
			data->result += ft_strlen(data->datastr);
		else
			data->result += data->val_precission;
	}
	else if (data->type == character)
	{
		data->datachar = va_arg(ap, int);
		data->result += 1;
	}
	else if(data->type == percent)
	{
		data->datachar = '%';
		data->result += 1;
	}
	else if(data->type == pointer)
	{
		data->datapointer = va_arg(ap, long);
		data->result += ft_generallen(data);
	}
	ft_printfnbr(data);
	return (0);
}

int		is_flag(char flag)
{
	return (flag == zero || flag == leffield || flag == takearg 
			|| flag == precision || (flag > '0' && flag <= '9'));
}

int		read_flag(t_datatype *data, va_list ap)
{
	int move;

	move = 1;
	if (*data->format == leffield)
		data->fleffield = 1;
	else if (*data->format == zero)
	{
		data->fzero = 1;
		return (move);
	}
	else if (*data->format == precision)
		data->fprecision = 1;
	else if (*data->format == takearg)
	{
		if (!data->fprecision)
		{
			data->ftakearglenght = 1;
			data->lenght_arg = va_arg(ap, int);
		}
		else
		{
			data->val_precission = va_arg(ap, int);
			data->ftakeargprecission = 1;
		}
	}
	if (*data->format > '0' && *data->format <= '9' && !data->fprecision)
	{
		move = 0;
		data->lenght_arg = *data->format++ - '0';
	}
	while (*data->format >= '0' && *data->format <= '9' && !data->fprecision)
		data->lenght_arg = (data->lenght_arg * 10) + (*data->format++ - '0');
	if (*data->format > '0' && *data->format <= '9' && data->fprecision)
	{
		move = 0;
		data->val_precission = *data->format++ - '0';
	}
	while (*data->format >= '0' && *data->format <= '9' && data->fprecision)
		data->val_precission = (data->val_precission * 10) + (*data->format++ - '0');
	return (move);
}
