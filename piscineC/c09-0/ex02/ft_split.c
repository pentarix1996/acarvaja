/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:24:33 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 03:31:06 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_word(char c, char before, char *charset)
{
	return (!is_separator(c, charset) && is_separator(before, charset));
}

int		words_count(char *str, char *charset)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_word(str[i], str[i - 1], charset) ||
			(!is_separator(str[i], charset) && i == 0))
			count++;
		i++;
	}
	return (count);
}

int		*obtain_size(char *str, char *charset)
{
	int		indx;
	int		i;
	int		count;
	int		*size;

	i = 0;
	count = words_count(str, charset);
	size = malloc(count * sizeof(int));
	while (i <= count)
	{
		size[i] = 0;
		i++;
	}
	i = 0;
	indx = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset))
			size[indx]++;
		else if (i > 0 && !is_separator(str[i - 1], charset))
			indx++;
		i++;
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		j;
	int		indx;
	int		*size;

	words = malloc((words_count(str, charset) + 1) * sizeof(char*));
	size = obtain_size(str, charset);
	indx = 0;
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (!is_separator(str[i], charset))
		{
			if (i == 0 || is_word(str[i], str[i - 1], charset))
				words[indx] = malloc(size[indx] * sizeof(char));
			words[indx][j] = str[i];
			words[indx][++j] = '\0';
		}
		else if (i > 0 && !is_separator(str[i - 1], charset) && ++indx)
			j = 0;
	}
	words[words_count(str, charset)] = 0;
	return (words);
}
