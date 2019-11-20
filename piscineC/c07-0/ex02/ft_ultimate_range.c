/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:01:37 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 02:15:24 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	int				*tab;
	unsigned int	tam;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tam = max - min;
	tab = malloc(sizeof(int) * tam);
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < tam)
		tab[i++] = min++;
	range = malloc(sizeof(int *) * 2);
	*range = malloc(sizeof(int) * tam);
	if (!*range)
		return (-1);
	*range = tab;
	return (i);
}
