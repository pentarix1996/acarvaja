/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:15:19 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/24 20:52:21 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int tam;

	tam = 0;
	while (str[tam] != '\0')
		tam++;
	return (tam);
}

char				*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*table;
	int			i;

	table = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!table)
		return (table);
	i = 0;
	while (i < ac)
	{
		table[i].size = ft_strlen(av[i]);
		table[i].str = av[i];
		table[i].copy = (char *)malloc(sizeof(char) * (table[i].size + 1));
		table[i].copy = ft_strcpy(table[i].copy, table[i].str);
		i++;
	}
	table[i].str = 0;
	return (table);
}
