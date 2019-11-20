/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:53:07 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/05 20:46:36 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	try_write(char i, char j, char z)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(z);
	if (i != '7' || j != '8' || z != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int dig_one;
	int dig_two;
	int dig_three;

	dig_one = 0;
	while (dig_one <= 9)
	{
		dig_two = dig_one + 1;
		while (dig_two <= 9)
		{
			dig_three = dig_two + 1;
			while (dig_three <= 9)
			{
				try_write(dig_one + '0', dig_two + '0', dig_three + '0');
				++dig_three;
			}
			++dig_two;
		}
		++dig_one;
	}
}
