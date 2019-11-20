/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:29:32 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/24 20:49:52 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* ex01 */
#include "ft_boolean.h"

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

/*int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}*/

/* ex02 */
#include "ft_abs.h"

/*int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("%d\n", ABS(3));
	printf("%d\n", ABS(-2147483647));
	printf("%d", ABS(0));
	return (0);
}*/

/* ex03 */
#include "ft_point.h"
void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

/*int main(void)
{
	t_point point;
	set_point(&point);
	return (0);
}*/

/* ex04 */
#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str)
{
	int tam;

	tam = 0;
	while (str[tam] != '\0')
		tam++;
	return (tam);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *table;
	int i;

	table = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!table)
		return (table);
	i = 0;
	while (i < ac)
	{
		table[i].size = ft_strlen(av[i]);
		table[i].str = av[i];
		table[i].copy = (char *)malloc(sizeof(char) * (table[i].size + 1));
		table[i].copy = ft_strcpy(table[i].copy, table[i].str);
		i++;
	}
	table[i].str = 0;
	return (table);
}

/*int main(void)
{
	t_stock_str *table;
	char **strs;
	int i;

	strs = malloc(sizeof(char *) * 5);
	strs[0] = malloc(sizeof(char) * 5);
	strs[1] = malloc(sizeof(char) * 4);
	strs[2] = malloc(sizeof(char) * 4);
	strs[3] = malloc(sizeof(char) * 10);
	strs[4] = malloc(sizeof(char));
	
	strs[0] = "Hola";
	strs[1] = "que";
	strs[2] = "tal";
	strs[3] = "estas tu?";
	strs[4] = "\0";
	table = ft_strs_to_tab(4, strs);
	i = 0;
	while (table[i].str)
	{
		printf("Elemento: %d -> tam: %d, Str: %s, Cpy: %s\n", i, table[i].size, table[i].str, table[i].copy);
		i++;
	}
	return (0);
}*/

/* ex05 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb != -2147483648)
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


void ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}

int main(void)
{
	t_stock_str *table;
	char **strs;

	strs = malloc(sizeof(char *) * 5);
	strs[0] = malloc(sizeof(char) * 5);
	strs[1] = malloc(sizeof(char) * 4);
	strs[2] = malloc(sizeof(char) * 4);
	strs[3] = malloc(sizeof(char) * 10);
	strs[4] = malloc(sizeof(char));
	
	strs[0] = "Hola";
	strs[1] = "que";
	strs[2] = "tal";
	strs[3] = "estas tu?";
	strs[4] = "\0";
	table = ft_strs_to_tab(4, strs);
	table[0].copy = "Adios";
	ft_show_tab(table);
	return (0);
}