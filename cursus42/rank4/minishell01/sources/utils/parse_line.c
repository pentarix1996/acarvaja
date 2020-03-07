/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:07:59 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 16:46:51 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		put_bar(char *str, char **tmp, int *i, char *c)
{
	int		bar;
	int		j;

	bar = msh_bar_count(str, i);
	if (bar == 1 && !c[1])
	{
		**tmp = '\\';
		(*tmp)++;
	}
	j = 0;
	while (j < bar)
	{
		if ((j % 2) || (c[1] && !c[0]))
		{
			**tmp = '\\';
			(*tmp)++;
		}
		j++;
	}
	return (bar);
}

char	*msh_parse_qt(char *s, int *i, char *c, t_var *var)
{
	char	*ptr;
	char	*tmp;
	int		bar;

	ptr = (char *)ft_calloc(PATH_MAX, 1);
	tmp = ptr;
	while (s[*i] && !(s[*i] == c[0] && !(bar % 2)) && !((s[*i] == c[1] &&
		(!c[0] || !(bar % 2)))) && s[*i] != c[2])
	{
		if (s[*i] == '\\')
			bar = put_bar(s, &tmp, i, c);
		else if (s[*i] == '$' && !(bar % 2) && c[0] == '"')
		{
			*i += msh_var_swap(&s[*i], &tmp, var);
			bar = 0;
		}
		else
		{
			*tmp++ = s[(*i)++];
			bar = 0;
		}
	}
	tmp = 0;
	*i += (!c[0] || !c[1]) ? 1 : 0;
	return (ptr);
}

void	fill_char_array(char pos, char *c)
{
	if (pos == '\'')
	{
		c[0] = 0;
		c[1] = '\'';
		c[2] = 0;
	}
	else if (pos == '"')
	{
		c[0] = '"';
		c[1] = 0;
		c[2] = 0;
	}
	else
	{
		c[0] = '"';
		c[1] = '\'';
		c[2] = ' ';
	}
}

int		fill_argument_array(int *k, char *line, char **tmp, t_var *var)
{
	char	c[3];
	char	*tmp2;
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	fill_char_array(line[i], c);
	if (*k && !i)
	{
		if (line[i] == '"' || line[i] == '\'')
			i++;
		tmp2 = ft_strjoin(tmp[--(*k)], msh_parse_qt(line, &i, c, var));
		free(tmp[*k]);
		tmp[(*k)++] = tmp2;
	}
	else if (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
			i++;
		tmp[(*k)++] = msh_parse_qt(line, &i, c, var);
	}
	return (i);
}

char	**msh_parse_line(char **line, t_var *var)
{
	char	**tmp;
	int		k;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * MAX_PITS);
	k = 0;
	i = 0;
	while (line[0][i] != 0)
		i += fill_argument_array(&k, &line[0][i], tmp, var);
	tmp[k] = NULL;
	return (tmp);
}
