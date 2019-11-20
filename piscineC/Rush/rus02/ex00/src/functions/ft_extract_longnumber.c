/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_longnumber.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:00:26 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 13:24:26 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_extract_error(char *str, int line);

char	*extract_ln(char *src)
{
	char	*nbr;
	int		i;

	i = 0;
	while (src[i] <= '9' && src[i] >= '0')
		i++;

	if (i == 0)
	{
		ft_extract_error("Error de extracción en el diccionario.", (char)i);
	}
	nbr = (char*)malloc(sizeof(char) * i);
	i = 0;
	while (src[i] <= '9' && src[i] >= '0')
	{
		nbr[i] = src[i];
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}
