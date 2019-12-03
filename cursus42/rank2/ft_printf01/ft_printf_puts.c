/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:16:45 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 11:22:04 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_putunbr(unsigned int nb)
{
	if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		ft_putunbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_putnbr(int nb, int singneg)
{
	if (nb != -2147483648)
	{
		if (nb < 10 && nb >= 0)
			ft_putchar(nb + '0');
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
