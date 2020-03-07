/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_inc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:09:55 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/15 15:46:17 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *str, char c)
{
	int		word;

	word = 0;
	while (*str)
	{
		if (*str && *str != c)
		{
			word++;
			while (*str && *str != c)
				str++;
		}
		str++;
	}
	return (word);
}

static int		size(char const *str, char c, size_t pos)
{
	int		size;

	while (*(str + pos) == c && *(str + pos))
		pos++;
	size = pos;
	while (*(str + pos) != c && *(str + pos) != 0)
	{
		size++;
		pos++;
	}
	return (size);
}

static char		*fill(char *word, char const *str, char c, size_t pos)
{
	size_t	let;

	let = 0;
	while (*(str + pos) == c && *(str + pos))
	{
		*(word + let) = *(str + pos);
		let++;
		pos++;
	}
	while (*(str + pos) != 0 && *(str + pos) != c)
	{
		*(word + let) = *(str + pos);
		let++;
		pos++;
	}
	*(word + let) = 0;
	return (word);
}

static char		**allocation(char **split, char c, char const *str, size_t pos)
{
	size_t	let;
	size_t	start;
	int		word;

	start = pos;
	word = 0;
	while (*(str + start) != 0)
	{
		let = size(str, c, pos);
		if (0 == (*(split + word) = (char *)malloc(sizeof(char) * (let + 1))))
			return (NULL);
		*(split + word) = fill(*(split + word), str, c, pos);
		start += ft_strlen(*(split + word));
		word++;
		pos = start;
	}
	*(split + word) = NULL;
	return (split);
}

char			**ft_split_inc(char const *str, char c)
{
	size_t	pos;
	int		word;
	char	**split;

	if (!str)
		return (NULL);
	word = count_word(str, c);
	if (NULL == (split = (char **)malloc(sizeof(char *) * (word + 1))))
		return (0);
	pos = 0;
	allocation(split, c, str, pos);
	return (split);
}
