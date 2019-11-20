/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:44:30 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/07 18:14:43 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_numbers(int number)
{
	if (number < 10)
	{
		ft_putchar('0');
		ft_putchar(number + '0');
	}
	else
	{
		ft_putchar(number / 10 + '0');
		ft_putchar(number % 10 + '0');
	}
}

void	try_write(int i, int j)
{
	print_numbers(i);
	ft_putchar(' ');
	print_numbers(j);
	if (i != 98 || j != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int number_one;
	int number_two;

	number_one = 0;
	while (number_one <= 99)
	{
		number_two = number_one + 1;
		while (number_two <= 99)
		{
			if (number_one != number_two)
			{
				try_write(number_one, number_two);
			}
			++number_two;
		}
		++number_one;
	}
}
