/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:30:49 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/26 19:08:32 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*ptr;
	long	i;
	long	minl;
	long	maxl;

	maxl = max;
	minl = min;
	ptr = 0;
	if (min >= max)
		return (ptr);
	ptr = malloc(sizeof(int) * (maxl - minl));
	if (!ptr)
		return (ptr);
	i = 0;
	while (i < (maxl - minl))
		ptr[i++] = minl++;
	return (ptr);
}
