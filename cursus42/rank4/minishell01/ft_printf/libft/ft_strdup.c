/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:29:48 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/20 19:18:18 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!src)
		return (NULL);
	else
	{
		if (!(dest = malloc(ft_strlen(src) + 1)))
			return (NULL);
		ft_strcpy(dest, src);
	}
	return (dest);
}
