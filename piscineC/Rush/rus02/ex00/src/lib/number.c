/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:02:11 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:44:39 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "number.h"

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*reserve_memorynbr(char *next, char *nbr);
char	*reserve_memorynbrstr(char *next, char *nbrstr);
char	*set_nbrstr(char *nbrstr, t_nbrtree binary);
char	*set_nbr(char *nbr, t_nbrtree binary);

int		ft_isnbr(char *str)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		else
			str++;
	}
	return (1);
}

int		compare(char *dest, char *src)
{
	while (*dest && *src)
	{
		if (*dest != *src)
			return (0);
		dest++;
		src++;
	}
	return (*src == '\0');
}

int		ft_strstr_tunned(char *str, char *to_find)
{
	int i;

	i = 0;
	if (*to_find == '\0')
		return (i);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (i);
		str++;
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		calc_range(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 1;
	j = 0;
	ptr = str;
	while (charset[j] != '\0')
		j++;
	while (ft_strstr_tunned(ptr, charset) != 0)
	{
		ptr = ft_strstr(ptr, charset);
		k = j;
		while (k-- > 0)
			ptr++;
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**table;
	int		mem_range;

	mem_range = calc_range(str, charset);
	table = malloc(sizeof(char *) * mem_range);
	if (table == NULL)
		return (table);
	j = 0;
	while (charset[j] != '\0')
		j++;
	i = 0;
	while (ft_strstr_tunned(str, charset) != 0)
	{
		table[i] = malloc(sizeof(char) * 200);
		mem_range = ft_strstr_tunned(str, charset);
		table[i] = ft_strncpy(table[i], str, mem_range);
		str = ft_strstr(str, charset);
		mem_range = j;
		while (mem_range-- > 0)
			str++;
		i++;
	}
	if (i == 0)
	{
		table[i] = malloc(sizeof(char) * 200);
		table[i++] = str;
	}
	else
		table[i++] = str;
	return (table);
}

t_nbrtree	*move_right_on_tree(t_nbrtree *binary, int n)
{
	while (n-- > 0)
		binary = binary->right;
	return (binary);
}

t_nbrtree	*move_left_on_tree(t_nbrtree *binary, int n)
{
	while (n-- > 0)
		binary = binary->left;
	return (binary);
}
