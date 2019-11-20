/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:01:37 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/26 19:08:10 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	long	maxl;
	long	minl;
	long	i;
	int		*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	maxl = max;
	minl = min;
	buffer = malloc(sizeof(int) * (maxl - minl));
	if ((maxl - minl) > 2147483647 || !buffer)
		return (-1);
	if (!buffer)
		return (-1);
	i = 0;
	while (i < (maxl - minl))
	{
		buffer[i] = min++;
		i++;
	}
	*range = buffer;
	return (maxl - minl);
}
