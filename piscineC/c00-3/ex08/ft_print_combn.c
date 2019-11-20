/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:08:33 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 15:58:16 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int *arr, int tam)
{
	int i;
	int print;

	print = 1;
	i = 0;
	while (i < tam - 1)
	{
		if (arr[i] >= arr[i + 1])
			print = 0;
		i++;
	}
	if (print == 1)
	{
		i = 0;
		while (i < tam)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
		if (arr[0] < (10 - tam))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

int		*fill_array(int *arr, int tam)
{
	int i;

	i = 0;
	while (i < tam)
	{
		arr[i] = i;
		i++;
	}
	return (arr);
}

void	ft_print_combn(int n)
{
	int i;
	int digits[10];

	if (n < 10 && n > 0)
	{
		fill_array(digits, n);
		while (digits[0] <= (10 - n))
		{
			print_number(digits, n);
			digits[n - 1]++;
			i = n;
			while (i && n > 1)
			{
				i--;
				if (digits[i] > 9)
				{
					digits[i - 1]++;
					digits[i] = 0;
				}
			}
		}
	}
}
