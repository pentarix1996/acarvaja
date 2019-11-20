/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aportill <aportill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:42:48 by aportill          #+#    #+#             */
/*   Updated: 2019/09/08 20:11:55 by aportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char output);

int		is_limit(int coll, int row, int x, int y)
{
	int result;

	result = 0;
	if ((row == 1 && coll != 1) && (row == 1 && coll != x))
	{
		result = 1;
	}
	else if ((row == y && coll != 1) && (row == y && coll != x))
	{
		result = 1;
	}
	else if ((row != 1 && coll == 1) && (row != y && coll == 1))
	{
		result = 1;
	}
	else if ((row != 1 && coll == x) && (row != y && coll == x))
	{
		result = 1;
	}
	return (result);
}

void	print_corner(int type_corner)
{
	if (type_corner == 1)
	{
		ft_putchar('A');
	}
	else if (type_corner == 2)
	{
		ft_putchar('C');
	}
}

int		is_corner_print(int coll, int row, int x, int y)
{
	int result;
	int type_corner;

	type_corner = 0;
	result = 0;
	if (row == 1 && (coll == 1 || coll == x))
	{
		type_corner = 1;
		result = 1;
	}
	else if (row == y && (coll == 1 || coll == x))
	{
		type_corner = 2;
		result = 1;
	}
	print_corner(type_corner);
	return (result);
}

void	print_cell(int coll, int row, int x, int y)
{
	if (!is_limit(coll, row, x, y) && !is_corner_print(coll, row, x, y))
	{
		ft_putchar(' ');
	}
	else if (is_limit(coll, row, x, y))
	{
		ft_putchar('B');
	}
}

void	rush(int x, int y)
{
	int coll;
	int row;

	coll = 1;
	row = 1;
	while (row <= y)
	{
		while (coll <= x)
		{
			print_cell(coll, row, x, y);
			coll++;
		}
		coll = 1;
		row++;
		ft_putchar('\n');
	}
}
