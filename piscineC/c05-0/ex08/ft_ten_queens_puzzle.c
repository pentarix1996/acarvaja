/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:46:37 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/17 19:53:51 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid_rules(int table[10][10], int i, int stape)
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

int		print_solve(int table[10][10])
{
	int		i;
	int		j;
	char	queen;

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

int		solve_puzzle(int table[10][10], int stape)
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

int		ft_ten_queens_puzzle(void)
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
