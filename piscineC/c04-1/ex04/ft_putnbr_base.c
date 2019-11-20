/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:37:13 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/18 19:24:51 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

int		is_correct_base(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_number(int nbr, char *base)
{
	int numb;

	numb = nbr;
	if (nbr == -2147483648)
	{
		print_number(-(nbr / ft_strlen(base)), base);
		print_number(-(nbr % ft_strlen(base)), base);
		return ;
	}
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr >= ft_strlen(base))
	{
		print_number(nbr / ft_strlen(base), base);
		print_number(nbr % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				lenght;
	unsigned int	number;

	if (is_correct_base(base) != 0)
	{
		lenght = ft_strlen(base);
		if (nbr < 0)
			ft_putchar('-');
		number = nbr;
		print_number(number, base);
	}
}
