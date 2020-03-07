/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:32:11 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/19 13:09:55 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		count_commands(char *line, char c, char d)
{
	int count;
	int	barra;
	int	qt;
	int	sqt;

	qt = 0;
	sqt = 0;
	count = 0;
	while (*line)
	{
		barra = 0;
		while (*line == '\\')
		{
			barra++;
			line++;
		}
		if (*line == '"' && !(barra % 2) && !sqt)
			qt = !qt ? 1 : 0;
		if (*line == '\'' && !qt)
			sqt = (!sqt && !(barra % 2)) ? 1 : 0;
		if ((*line == c || *line == d) && !sqt && !qt && !(barra % 2))
			count++;
		line++;
	}
	return (line ? count : 0);
}

void	sum_var(int *i, int *barra, char **line)
{
	(*barra)++;
	(*line)++;
	(*i)++;
}

int		parse_commands(char *line, char c, char d)
{
	int		barra;
	int		qt;
	int		sqt;
	int		i;

	qt = 0;
	sqt = 0;
	i = 0;
	while (*line)
	{
		barra = 0;
		while (*line == '\\')
			sum_var(&i, &barra, &line);
		if (*line == '"' && !(barra % 2) && !sqt)
			qt = !qt ? 1 : 0;
		if (*line == '\'' && !qt)
			sqt = (!sqt && !(barra % 2)) ? 1 : 0;
		if ((*line == c || *line == d) && !sqt && !qt && !(barra % 2))
			return (i);
		line++;
		i++;
	}
	return (i);
}
