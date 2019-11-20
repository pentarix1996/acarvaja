/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:20:46 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/17 17:40:01 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* ex00 */
int ft_iterative_factorial(int nb)
{
	int fact;

	if (nb < 0)
		return (0);
	fact = 1;
	while (nb > 1)
		fact *= nb--;
	return (fact);
}

/*int main(void)
{
	printf("%d", ft_iterative_factorial(10));
	return (0);
}*/

/* ex01 */
int ft_recursive_factorial(int nb)
{
	int fact;

	fact = 1;
	if (nb < 0)
		return (0);
	if (nb > 1)
		fact = nb * ft_recursive_factorial(nb - 1);
	return (fact);
}

/*int main(void)
{
	printf("%d", ft_recursive_factorial(10));
	return (0);
}*/

/* ex02 */
int ft_iterative_power(int nb, int power)
{
	int result;
	
	if (power < 0)
		return (0);
	result = 1;
	while (power-- >= 1)
		result *= nb;
	return (result);
}

/*int main(void)
{
	printf("%d", ft_iterative_power(3,2));
	return (0);
}*/
/* ex03 */
int ft_recursive_power(int nb, int power)
{
	int result;
	
	if (power < 0)
		return (0);
	result = 1;
	if (power >= 1)
		result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}

/*int main(void)
{
	printf("%d", ft_recursive_power(0, 0));
	return (0);
}*/

/* ex04 */
int ft_fibonacci(int index)
{
	int fibbo;

	fibbo = 0;
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	else
		fibbo += ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	
	return (fibbo);
}

/*int main(void)
{
	printf("%d", ft_fibonacci(0));
	return (0);
}*/

/* ex05 */
int ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		else if (i * i > nb)
			return (0);
		i++;
	}
	return (0);
}

/*int main(void)
{
	printf("%d", ft_sqrt(46340 * 46340));
	return (0);
}*/

/* ex06 */
int    ft_is_prime(int nb)
{
    int    i;
    int    div;
    if (nb <= 1)
        return (0);
    i = 2;
    div = 0;
    while (i <= nb / i)
    {
        if (nb % i == 0)
            div++;
        if (div >= 1)
            return (0);
        i++;
    }
    return (1);
}

/*int main(void)
{
	//2142761603. es primo.
	printf("%d", ft_is_prime(1000003));
	return (0);
}*/

/* ex07 */
int ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		while (ft_is_prime(nb) != 1)
			nb++;
	return (nb);
}

/*int main(void)
{
	printf("%d\n", ft_find_next_prime(2142761603));
	printf("%d", ft_is_prime(2142761603));
	return (0);
}*/

/* ex08 */
int	valid_rules(int table[10][10], int i, int stape)
{
	int j;
	int k;
	int result;

	j = -1;
	result = 1;
	while (++j < 10)
		if (table[i][j] == 1)
			return (0);
	j = -1;
	k = -1;
	while (++j < 10)
	{
		while (++k < 10)
		{
			if (j - k == i - stape && table[j][k] == 1)
				return (0);
			else if (j + k == i + stape && table[j][k] == 1)
				return (0);
		}
		k = -1;
	}
	return (result);
}

int	print_solve(int table[10][10])
{
	int i;
	int j;
	char queen;

	i = -1;
	j = -1;
	while (++i < 10)
	{
		while (++j < 10)
		{
			if (table[i][j] == 1)
			{
				queen = j + '0';
				write(1, &queen, 1);
			}
		}
		j = -1;
	}
	return (1);
}

int solve_puzzle(int table[10][10], int stape)
{
	int i;
	int counter;

	i = -1;
	counter = 0;
	if (stape < 10)
	{
		while (++i < 10)
		{
			if (valid_rules(table, i, stape) != 0)
			{
				table[i][stape] = 1;
				counter += solve_puzzle(table, stape + 1);
				table[i][stape] = 0;
			}
		}
	}
	else
	{
		counter += print_solve(table);
		write(1, "\n", 1);
	}
	return (counter);
}

int ft_ten_queens_puzzle(void)
{
	int table[10][10];
	int sols;
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 10)
	{
		while (++j < 10)
			table[i][j] = 0;
		j = -1;
	}
	sols = solve_puzzle(table, 0);
	return (sols);
}

/*int main(void)
{
	printf("%d", ft_ten_queens_puzzle());
	return (0);
}*/