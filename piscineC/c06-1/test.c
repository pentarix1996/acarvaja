/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:42:30 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/17 21:28:55 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ex00 */
void	ft_putstr(char *str)
{
	while (str[0] != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int main(int argc, char **argv)
{
	(void) argc;
	ft_putstr(argv[0]);
	write(1, "\n", 1);
}
/* ex01 */
/*int main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
}*/

/* ex02 */
/*int main(int argc, char **argv)
{
	while (--argc > 0)
	{
		ft_putstr(argv[argc]);
		write(1, "\n", 1);
	}
}*/

/* ex03 */
unsigned int	ft_strlen(char *str)
{
	unsigned int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

int				ft_strcmp(char *s1, char *s2)
{
	int				result;
	int				cmp1;
	unsigned	int	i;

	i = 0;
	cmp1 = 0;
	result = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i < ft_strlen(s1))
			result += (unsigned char)s1[i];
		if (i < ft_strlen(s2))
			cmp1 += (unsigned char)s2[i];
		if ((result - cmp1) < 0)
			break ;
		else if ((result - cmp1) > 0)
			break ;
		i++;
	}
	result -= cmp1;
	return (result);
}

void	ft_swap(char **a, char **b)
{
	char *swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(char **tab, int size)
{
	int i;
	int j;
	(void) tab;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0)
		{
			if (ft_strcmp(tab[j], tab[j - 1]) > 0)
			{
				ft_swap(&tab[j], &tab[j - 1]);
			}
			j--;
		}
		i++;
	}
}

/*int main(int argc, char **argv)
{
	argv++;
	ft_sort_int_tab(argv, argc - 1);
	while (--argc > 0)
	{
		ft_putstr(argv[argc-1]);
		write(1, "\n", 1);
	}
}*/