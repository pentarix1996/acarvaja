/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:04:26 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 12:52:17 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);
int		calc_range(char *str, char *charset);
int		ft_strstr_tunned(char *str, char *to_find);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	**ft_split(char *str, char *charset, int i, int j)
{
	char	**table;
	int		mem_range;

	table = malloc((calc_range(str, charset) + 1) * sizeof(char*));
	if (table == NULL)
		return (table);
	while (charset[j] != '\0')
		j++;
	while (ft_strstr_tunned(str, charset) != 0)
	{
		table[i++] = ft_strncpy(malloc(sizeof(char) * 200), str, ft_strstr_tunned(str, charset));
		str = ft_strstr(str, charset);
		mem_range = j;
		while (mem_range-- > 0)
			str++;
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
