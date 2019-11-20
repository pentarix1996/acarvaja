/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:12:12 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 02:53:21 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_correct_base(char *base);
int		ft_atoi_base(char *str, char *base);

char	insert_new_char(int nbr, char *base)
{
	char	res;
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	res = base[nbr % i];
	return (res);
}

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

char	*ft_putnbr_base(int nbr, char *base)
{
	int				i;
	char			*new_nbr;
	int				j;

	new_nbr = malloc(sizeof(char) * 200);
	if (is_correct_base(base) != 0)
	{
		i = 0;
		j = 0;
		while (base[j++] != '\0')
			j++;
		j--;
		while (nbr != 0)
		{
			if (nbr < 0)
			{
				new_nbr[0] = '-';
				nbr = nbr * -1;
				i++;
			}
			new_nbr[i] = insert_new_char(nbr, base);
			nbr /= j;
			i++;
		}
	}
	return (revert(new_nbr));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		realnbr;
	char	*new_nbr;

	if (is_correct_base(base_from) == 0 || is_correct_base(base_to) == 0)
		new_nbr = NULL;
	else
	{
		realnbr = ft_atoi_base(nbr, base_from);
		new_nbr = ft_putnbr_base(realnbr, base_to);
	}
	return (new_nbr);
}
