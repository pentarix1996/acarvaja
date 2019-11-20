/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolina- <pmolina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:42:48 by aportill          #+#    #+#             */
/*   Updated: 2019/09/08 16:53:44 by pmolina-         ###   ########.fr       */
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
		result = 2;
	}
	else if ((row != 1 && coll == x) && (row != y && coll == x))
	{
		result = 2;
	}
	return (result);
}

void	print_corner(int type_corner)
{
	if ((type_corner == 1) || (type_corner == 2))
	{
		ft_putchar('o');
	}
}

int		is_corner_print(int coll, int row, int x, int y)
{
	int result;
	int type_corner;

	type_corner = 0;
	result = 0;
	if ((row == 1 && coll == 1) || (row == y && coll == x))
	{
		if ((y == 1 && coll == x && x != 1) || (x == 1 && row == y && y != 1))
		{
			type_corner = 2;
		}
		else
		{
			type_corner = 1;
		}
		result = 1;
	}
	else if ((row == y && coll == 1) || (row == 1 && coll == x))
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
	else if (is_limit(coll, row, x, y) == 1)
	{
		ft_putchar('-');
	}
	else if(is_limit(coll, row, x, y) == 2)
	{
		ft_putchar('|');
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
