/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:25:24 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/29 19:16:40 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				result;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	while (*aux_s1 != '\0' || *aux_s2 != '\0')
	{
		result = *aux_s1 - *aux_s2;
		if (result != 0)
			return (result);
		aux_s1++;
		aux_s2++;
	}
	return (0);
}
