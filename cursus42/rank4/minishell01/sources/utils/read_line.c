/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:52:10 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 18:01:36 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt_quote(int *qt, int *sqt)
{
	if (*qt)
		ft_printf("        \e[38;5;147m\"~\e[38;5;183m> \e[0m");
	else if (*sqt)
		ft_printf("        \e[38;5;147m\'~\e[38;5;183m> \e[0m");
}

void	read_until_quote(int *barra, int *qt, int *sqt, char **line)
{
	char	*aux;
	char	*tmp2;
	int		i;

	prompt_quote(qt, sqt);
	get_next_line(0, &aux);
	tmp2 = ft_strjoin(*line, "\n");
	free(*line);
	*line = ft_strjoin(tmp2, aux);
	free(tmp2);
	i = -1;
	while (aux[++i])
	{
		*barra = 0;
		while (aux[i] == '\\')
		{
			(*barra)++;
			i++;
		}
		if (aux[i] == '"' && !(*barra % 2) && !*sqt)
			*qt = !*qt ? 1 : 0;
		if (aux[i] == '\'' && !*qt)
			*sqt = (!*sqt && !(*barra % 2)) ? 1 : 0;
	}
	free(aux);
}

void	msh_read_line(char **line)
{
	int		qt;
	int		sqt;
	int		i;
	int		barra;

	if (get_next_line(0, line) <= 0)
		exit(0);
	qt = 0;
	sqt = 0;
	i = 0;
	while (line[0][i])
	{
		barra = 0;
		while (line[0][i] == '\\')
		{
			barra++;
			i++;
		}
		if (line[0][i] == '"' && !(barra % 2) && !sqt)
			qt = !qt ? 1 : 0;
		if (line[0][i++] == '\'' && !qt)
			sqt = (!sqt && !(barra % 2)) ? 1 : 0;
	}
	while (qt || sqt)
		read_until_quote(&barra, &qt, &sqt, line);
}
