/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:21:13 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/07 19:17:52 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ex01 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* ex02 */
void	ft_print_alphabet(void)
{
	char alf;
	char last_char;

	alf = 'a';
	last_char = 'z' + 1;
	while (alf != last_char)
	{
		write(1, &alf, 1);
		alf++;
	}
}

/* ex03 */
void	ft_print_reverse_alphabet(void)
{
	char alf;
	char last_char;

	alf = 'z';
	last_char = 'a' - 1;
	while (alf != last_char)
	{
		write(1, &alf, 1);
		alf--;
	}
}

/* ex04 */
void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		write(1, "P", 1);
	}
	else
	{
		write(1, "N", 1);
	}
}

/* ex05 */
void	try_write(char i, char j, char z)
{
	if(i != j && i != z && j != z)
	{
		ft_putchar(i);
		ft_putchar(j);
		ft_putchar(z);

		if(i != '7' || j != '8' || z != '9')
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}

}

void	ft_print_comb(void){
	int dig_one;
	int dig_two;
	int dig_three;

	dig_one = 0;
	while(dig_one <= 9)
	{
		dig_two = dig_one + 1;
		while(dig_two <= 9)
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

/* ex06 */
void	print_numbers(int number)
{

	if(number < 10){
		ft_putchar('0');
		ft_putchar(number + '0');
	}
	else
	{
		ft_putchar(number / 10 + '0');
		ft_putchar(number % 10 + '0');
	}
}

void	try_write2(int i, int j)
{
	print_numbers(i);
	ft_putchar(' ');
	print_numbers(j);
	
	if(i != 98 || j != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void){
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
				try_write2(number_one, number_two);
			}
			++number_two;
		}
		++number_one;
	}
}

/* ex07 */
void	ft_putnbr(int nb)
{
	if(nb != -2147483648)
	{
		if (nb < 10 && nb >= 0)
		{
			ft_putchar(nb + '0');
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
		else
		{
			ft_putchar('-');
			ft_putnbr(nb * -1);
		}
	}
	else
	{
		write(1, "-2147483648", 11);
	}
	
}

/* ex08 */
void print_number(int *arr, int tam)
{
	int i;
	int print;

	print = 1;
	i = 0;
	while (i < tam - 1)
	{
		if (arr[i] >= arr[i + 1])
		{
			print = 0;
		}	
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

int *fill_array(int *arr, int tam)
{
	int i;

	i = 0;
	while (i < tam)
	{
		arr[i] = i;
		i++;
	}

	return arr;
}

void ft_print_combn2(int n)
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
				if(digits[i] > 9)
				{
					digits[i - 1]++;
					digits[i] = 0;
				}
			}
		}
	}
}

int main()
{
	ft_putnbr(2147483647);
}
