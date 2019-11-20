/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:29:22 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/10 19:06:53 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char put)
{
	write(1, &put, 1);
}

void	print_memory_hexa(unsigned long int number)
{
	char	*trans;
	char	hexa[15];
	int		i;

	i = 14;
	trans = "0123456789abcdef";
	while (number > 0)
	{
		hexa[i] = trans[number % 16];
		number /= 16;
		i--;
	}
	i = 0;
	while (i < 15)
	{
		if (hexa[i] >= '0' && hexa[i] <= 'f')
			write(1, &hexa[i], 1);
		else
			ft_putchar('0');
		i++;
	}
	write(1, ": ", 2);
}

void	decimal_to_hexa2(char transf, int j)
{
	char	*hexa;
	char	to[2];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < 2)
	{
		to[i] = hexa[transf % 16];
		transf /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(to[i]);
		i--;
	}
	if (j % 2)
		write(1, " ", 1);
}

void	print_special_chars(char *ptr, unsigned int size, unsigned int i)
{
	int		j;
	char	c;

	j = 0;
	while (j < 16)
	{
		c = ptr[j];
		if (c >= ' ' && c <= '~')
			write(1, &ptr[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
	if (i < (size - 17))
		write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned	int			j;
	unsigned	int			i;
	unsigned	long	int mem;
	char					*ptr;

	ptr = addr;
	j = 0;
	i = 0;
	mem = (unsigned long int)addr;
	while (i < size - 1)
	{
		print_memory_hexa(mem);
		while (j < 16)
		{
			decimal_to_hexa2(ptr[j], j);
			j++;
		}
		j = 0;
		print_special_chars(ptr, size, i);
		ptr += 16;
		mem += 16;
		i += 16;
	}
	return (addr);
}
