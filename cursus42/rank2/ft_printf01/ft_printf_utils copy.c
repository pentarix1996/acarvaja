/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:42:35 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/29 20:45:39 by acarvaja         ###   ########.fr       */
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

char	*next_type(char *format, int *result)
{
	int		i;
	char	*tmp;

	tmp = format;
	i = ft_strlen(format);
	while (i-- >= 0)
	{
		if (*tmp == percent)
			return ((char *)tmp);
		tmp++;
		*result += 1;
	}
	*result -= (ft_strlen(format) + 1);
	return (0);
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

int		ptint_p(va_list ap)
{
	unsigned long res;

	res = va_arg(ap, unsigned long);
	ft_putstr(ft_strjoin("0x", ft_atoa_lowexh(res)));
	return (ft_strlen(ft_atoa_lowexh(res)) + 2);
}

void	ft_putnbr(int nb, int nosign)
{
	if (nb != -2147483648)
	{
		if (nb < 10 && nb >= 0)
		{
			ft_putchar(nb + '0');
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10, nosign);
			ft_putchar(nb % 10 + '0');
		}
		else
		{
			if (!nosign)
				ft_putchar('-');
			ft_putnbr(nb * -1, nosign);
		}
	}
	else
	{
		write(1, "-2147483648", 11);
	}
}

int		ptint_lowexh(va_list ap)
{
	unsigned long res;

	res = va_arg(ap, unsigned long);
	ft_putstr(ft_atoa_lowexh(res));
	return (ft_strlen(ft_atoa_lowexh(res)));
}

int		ptint_upperexh(va_list ap)
{
	unsigned long res;

	res = va_arg(ap, unsigned long);
	ft_putstr(ft_atoa_upperexh(res));
	return (ft_strlen(ft_atoa_upperexh(res)));
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

int		do_num_type(va_list ap, int type, int *result)
{
	int				i;
	unsigned int	ui;

	if (type == decimal || type == integer)
	{
		
		i = va_arg(ap, int);
		ft_putnbr(i, 0);
		*result += ft_intlen(i);
		return (ft_intlen(i));
	}
	else if (type == unsgint)
	{
		ui = va_arg(ap, unsigned int);
		ft_putnbr(ui, 0);
		*result += ft_uintlen(ui);
		return (ft_uintlen(ui));
	}
	else if (type == exhlower)
		*result += ptint_lowexh(ap);
	else if (type == exhupper)
		*result += ptint_upperexh(ap);
	return (0);
}

void	print_spaces(int *flags, int diff, int *result, int is_str)
{
	if (!flags[1] || is_str)
	{
		if (flags[4] > diff)
		{
			flags[4] -= diff;
			while (flags[4]-- > 0)
			{
				if (flags[0])
					ft_putchar('0');
				else
					ft_putchar(' ');
				*result += 1;
			}
		}
	}
}

void	print_spaces_precision(int *flags, int diff, int *result, int is_str)
{
	int negative;

	negative = 0;
	if (flags[6] < 0)
	{
		diff--;
		negative = 1;
	}
	if (!is_str)
	{
		if (flags[4] > diff || flags[5] > diff)
		{
			flags[4] -= flags[5] + negative;
			while (flags[4]-- > 0 && !flags[1])
			{
				ft_putchar(' ');
				*result += 1;
			}
			if (flags[6] < 0)
				ft_putchar('-');
			while (flags[5]-- - (diff) > 0)
			{
				ft_putchar('0');
				*result += 1;
			}
		}
	}
}

int		ptint_lowexh_flags(va_list ap, int *flags, int *result)
{
	unsigned long res;

	res = va_arg(ap, unsigned long);
	if (!flags[3] && !flags[1])
		print_spaces(flags, ft_strlen(ft_atoa_lowexh(res)), result, 0);
	else if (flags[3])
		print_spaces_precision(flags, ft_strlen(ft_atoa_lowexh(res)), result, 0);
	*result += ft_strlen(ft_atoa_upperexh(res));
	ft_putstr(ft_atoa_lowexh(res));
	return (ft_strlen(ft_atoa_lowexh(res)));
}

int		ptint_upperexh_flags(va_list ap, int *flags, int *result)
{
	unsigned long res;

	res = va_arg(ap, unsigned long);
	if (!flags[3] && !flags[1])
		print_spaces(flags, ft_strlen(ft_atoa_upperexh(res)), result, 0);
	else if (flags[3])
		print_spaces_precision(flags, ft_strlen(ft_atoa_upperexh(res)), result, 0);
	*result += ft_strlen(ft_atoa_upperexh(res));
	ft_putstr(ft_atoa_upperexh(res));
	return (ft_strlen(ft_atoa_upperexh(res)));
}

int		do_num_type2(va_list ap, int type, int *result, int *flags)
{
	unsigned int	ui;
	int				diff;

	diff = 0;
	if (type == decimal || type == integer)
	{
		flags[6] = va_arg(ap, int);
		*result += ft_intlen(flags[6]);
		diff = ft_intlen(flags[6]);
		if (flags[6] < 0 && flags[0] && !flags[3])
			ft_putchar('-');
		if (!flags[3] && !flags[1])
			print_spaces(flags, diff, result, 0);
		else if (flags[3])
			print_spaces_precision(flags, diff, result, 0);
		if (flags[6] < 0 && !flags[0] && !flags[3])
			ft_putchar('-');
		ft_putnbr(flags[6], 1);
	}
	else if (type == unsgint)
	{
		ui = va_arg(ap, unsigned int);
		*result += ft_uintlen(ui);
		diff = ft_uintlen(ui);
		if (!flags[3] && !flags[1])
			print_spaces(flags, diff, result, 0);
		else if (flags[3])
			print_spaces_precision(flags, diff, result, 0);
		ft_putnbr(ui, 1);
	}
	else if (type == exhlower)
		diff += ptint_lowexh_flags(ap, flags, result);
	else if (type == exhupper)
		diff += ptint_upperexh_flags(ap, flags, result);
	return (diff);
}

int		do_str_type(va_list ap, int type, int *result)
{
	char	c;
	char	*s;

	if (type == string)
	{
		s = va_arg(ap, char *);
		if (!s)
		{
			*result += 6;
			ft_putstr("(null)");
			return (0);
		}
		if (*s < 0)
			return (-1);
		ft_putstr(s);
		*result += ft_strlen(s);
	}
	else if (type == character)
	{
		c = va_arg(ap, int);
		if (c < 0)
			return (-1);
		ft_putchar(c);
		*result += 1;
	}
	else if(type == percent)
	{
		ft_putchar(percent);
		*result +=1;
	}
	else if(type == pointer)
		*result += ptint_p(ap);
	return (0);
}

int		ptint_p2(va_list ap, int *result, int *flags)
{
	unsigned long res;

	res = va_arg(ap, unsigned long);
	if (flags[1] == 0)
		print_spaces(flags, ft_strlen(ft_atoa_lowexh(res)) + 2, result, 1);
	ft_putstr(ft_strjoin("0x", ft_atoa_lowexh(res)));
	*result += ft_strlen(ft_atoa_lowexh(res)) + 2;
	return (ft_strlen(ft_atoa_lowexh(res)) + 2);
}

int		do_str_type2(va_list ap, int type, int *result, int *flags)
{
	char	c;
	char	*s;
	int		diff;

	diff = 1;
	if (type == string)
	{
		s = va_arg(ap, char *);
		if (!s)
		{
			*result += 6;
			if (flags[1] == 0)
				print_spaces(flags, 6, result, 1);
			ft_putstr("(null)");
			return (6);
		}
		if (*s < 0)
			return (-1);
		if (flags[1] == 0)
			print_spaces(flags, ft_strlen(s), result, 1);
		ft_putstr(s);
		*result += ft_strlen(s);
		diff = ft_strlen(s);
	}
	else if (type == character)
	{
		c = va_arg(ap, int);
		if (c < 0)
			return (-1);
		if (flags[1] == 0)
			print_spaces(flags, 1, result, 1);
		ft_putchar(c);
		*result += 1;
	}
	else if(type == percent)
	{
		if (flags[1] == 0)
			print_spaces(flags, 1, result, 1);
		ft_putchar(percent);
		*result +=1;
	}
	else if(type == pointer)
		diff = ptint_p2(ap, result, flags);
	return (diff);
}

int		change_valor(int *flag)
{
	*flag = 1;
	return (1);
}

int		format_with_flags(int *flags, char *tmp, int *result, va_list ap)
{
	int	diff;
	int move;
	int is_numeral;

	move = 1;
	if ((is_numeral = is_numerical_type(*tmp)))
	{
		diff = do_num_type2(ap, (int)*tmp, result, flags);
		if (flags[3])
			move++;
		tmp++;
	}
	else
	{
		diff = do_str_type2(ap, (int)*tmp, result, flags);
		if (flags[3])
			move++;
		tmp++;
	}
	if (flags[1] && flags[3] && is_numerical_type(*tmp))
	{
		flags[4]++;
		while (flags[4]-- > 0 && flags[1])
		{
			ft_putchar(' ');
			*result += 1;
		}
	}
	if (flags[4] > diff)
	{
		flags[4] -= diff;
		while (flags[4]-- > 0 && flags[1])
		{
			ft_putchar(' ');
			*result += 1;
		}
	}
	return (move);
}

int		do_flag(char *tmp, int *result, va_list ap)
{
	static int	flags[7];
	static int	i;
	int			nbr;
	int			move;

	nbr = 0;
	move = 1;
	if (!i)
		i = 0;
	while (i < 4)
		flags[i++] = 0;
	if (*tmp == zero)
		return (flags[0] == 1 ? move : change_valor(&flags[0]));
	else if (*tmp == leffield)
		return (flags[1] == 1 ? 0 : change_valor(&flags[1]));
	else if (*tmp == takearg)
		return (flags[2] == 1 ? move : change_valor(&flags[2]));
	else if (*tmp == precision)
		return (flags[3] == 1 ? 0 : change_valor(&flags[3]));
	if (*tmp > '0' && *tmp < '9')
		flags[4] = *tmp++ - '0';
	while (*tmp >= '0' && *tmp < '9')
	{
		flags[4] = (flags[4] * 10) + (*tmp++ - '0');
		move++;
	}
	if (*tmp == precision)
	{
		change_valor(&flags[3]);
		tmp++;
	}
	while (*tmp >= '0' && *tmp < '9')
	{
		flags[5] = (flags[5] * 10) + (*tmp++ - '0');
		move++;
	}
	if (is_correct_type(*tmp))
		move += format_with_flags(flags, tmp, result, ap);
	return (move);
}

int		is_flag(char flag)
{
	return (flag == zero || flag == leffield || flag == takearg 
			|| flag == precision || (flag > '0' && flag <= '9'));
}
