/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:30:49 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 02:15:14 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*ptr;
	unsigned int	i;
	unsigned int	range;

	range = max - min;
	ptr = 0;
	if (min >= max)
		return (ptr);
	ptr = malloc(sizeof(int) * range);
	if (!ptr)
		return (ptr);
	i = 0;
	while (i < range)
		ptr[i++] = min++;
	return (ptr);
}
