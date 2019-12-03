/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:26:52 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 11:29:39 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swap(char *a, char *b)
{
	char swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

char	*revert(char *ptr)
{
	int j;
	int i;
	int k;

	i = 0;
	j = 0;
	while (ptr[j] != '\0')
		j++;
	k = j;
	j -= 1;
	if (ptr[0] == '-')
	{
		while (++i < k / 2 + 1)
			ft_swap(&ptr[i], &ptr[j--]);
	}
	else
	{
		while (i < k / 2)
			ft_swap(&ptr[i++], &ptr[j--]);
	}
	return (ptr);
}

char	*ft_atoa_lowexh(unsigned long nbr)
{
	char	*result;
	char	*pos;
	int		i;

	pos = "0123456789abcdef";
	result = malloc(sizeof(*result) * 16);
	i = 0;
	while (nbr >= 16)
	{
		result[i++] = pos[nbr % 16];
		nbr /= 16;
	}
	result[i] = pos[nbr % 16];
	revert(result);
	return (result);
}

char	*ft_atoa_upperexh(unsigned long nbr)
{
	char	*result;
	char	*pos;
	int		i;

	pos = "0123456789ABCDEF";
	result = malloc(sizeof(*result) * 16);
	i = 0;
	while (nbr >= 16)
	{
		result[i++] = pos[nbr % 16];
		nbr /= 16;
	}
	result[i] = pos[nbr % 16];
	revert(result);
	return (result);
}
