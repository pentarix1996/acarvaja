/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 09:00:35 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/02 11:12:02 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_printf
{
	int res;
	int pos;
	int prec;
	int fprecision;
	int width;
	char type;
	va_list arg;
}				t_printf;

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void init_struct(t_printf *p)
{
	p->res = 0;
	p->pos = 0;
	p->prec = 0;
	p->fprecision = 0;
	p->width = 0;
	p->type = '\0';
}

void read_flags(t_printf *p, const char *format)
{
	while (is_digit(format[p->pos]))
	{
		p->width = p->width * 10 + (format[p->pos] - '0');
		p->pos++;
	}
	if (format[p->pos] == '.')
	{
		p->fprecision = 1;
		p->pos++;
	}
	while (is_digit(format[p->pos]))
	{
		p->prec = p->prec * 10 + (format[p->pos] - '0');
		p->pos++;
	}
	p->type = format[p->pos];;
}

void p_spaces(int n)
{
	while (n-- > 0)
		ft_putchar(' ');
}

void p_zeros(int n)
{
	while (n-- > 0)
		ft_putchar('0');
}

int ft_nbrlen(unsigned int nbr)
{
	int i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_nbrlenx(unsigned int nbr)
{
	int i;

	i = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void ft_putnbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void ft_putnbrx(unsigned int nbr)
{
	char *base = "0123456789abcdef";
	if (nbr > 15)
		ft_putnbrx(nbr / 16);
	ft_putchar(base[nbr % 16]);
}

void ft_printx(t_printf *p)
{
	unsigned int nbr;
	int len = 0;
	int zeros = 0;
	int spaces = 0;

	nbr = va_arg(p->arg, unsigned int);
	len = ft_nbrlenx(nbr);
	if (p->prec > len)
	{
		if (p->width > p->prec)
			spaces = p->width - p->prec;
		zeros = p->prec - len;
	}
	else
	{
		if (p->width > len)
			spaces = p->width - len;
	}
	if (spaces > 0)
	{
		p_spaces(spaces);
		p->res += spaces;
	}
	if (zeros > 0)
	{
		p_zeros(zeros);
		p->res += zeros;
	}
	if (nbr == 0 && p->fprecision && p->prec == 0)
    {
		p_spaces(1);
	   	p->res += 1;
    }
	else
	{
		ft_putnbrx(nbr);
		p->res += len;
	}

}

void ft_printd(t_printf *p)
{
	int nb;
	unsigned int nbr;
	int len = 0;
	int zeros = 0;
	int spaces = 0;
	int sign = 0;

	nb = va_arg(p->arg, int);
	nbr = nb;
	if (nb < 0)
	{
		sign = 1;
		nbr *= -1;
	}
	len = ft_nbrlen(nbr);
	if (p->prec > len)
	{
		if (p->width > (p->prec + sign))
				spaces = p->width - p->prec - sign;
		zeros = p->prec - len;
	}
	else
	{
		if (p->width > (len + sign))
			spaces = p->width - len - sign;
	}
	if (spaces > 0)
	{
		p_spaces(spaces);
		p->res += spaces;
	}
	if (sign == 1)
	{
		ft_putchar('-');
		p->res++;
	}
	if (zeros > 0)
	{
		p_zeros(zeros);
		p->res += zeros;
	}
	if (nbr == 0 && p->fprecision && p->prec == 0)
    {
		p_spaces(1);
		p->res += 1;
    } 
	else
	{
		ft_putnbr(nbr);
		p->res += len;
	}
}

void ft_prints(t_printf *p)
{
	char *str;
	int len;

	str = va_arg(p->arg, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (p->fprecision && p->prec < len )
		len = p->prec;
	if (p->width > len)
	{
		p_spaces(p->width - len);
		p->res += p->width - len;
	}
	p->res = p->res + (write(1, str, len));
}

void read_type(t_printf *p)
{
	if (p->type == 's')
		ft_prints(p);
	else if (p->type == 'd')
		ft_printd(p);
	else if (p->type == 'x')
		ft_printx(p);
	p->fprecision = 0;
	p->type = '\0';
	p->width = 0;
	p->prec = 0;
}

int	ft_printf(const char *format, ...)
{
	t_printf *p;

	if (!(p = malloc(sizeof(t_printf))))
		return (0);
	va_start(p->arg, format);
	init_struct(p);
	while (format[p->pos])
	{
		if (format[p->pos] == '%')
		{
			p->pos++;
			read_flags(p, format);
			read_type(p);
		}
		else
		{
			ft_putchar(format[p->pos]);
			p->res++;
		}
		p->pos++;
	}
	va_end(p->arg);
	return (p->res);
}
