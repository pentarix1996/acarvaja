/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:27:03 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 15:08:16 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	long	ncpy;
	size_t	len;
	char	*str;

	ncpy = n;
	len = (ncpy > 0) ? 0 : 1;
	ncpy = (ncpy > 0) ? ncpy : -ncpy;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (0);
	*(str + len--) = '\0';
	while (ncpy > 0)
	{
		*(str + len--) = ncpy % 10 + '0';
		ncpy /= 10;
	}
	if (len == 0 && str[1] == '\0')
		*(str + len) = '0';
	if (len == 0 && str[1] != '\0')
		*(str + len) = '-';
	return (str);
}
